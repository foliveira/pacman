/***************************************************************
 * Definições do tipo cggl::ObjModel
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 ***************************************************************/

#include "objModel.h"

namespace cggl {

  ObjModel::ObjModel(char *_modelFileName, float _modelScale) 
  : modelFileName(_modelFileName), modelScale(_modelScale), model(NULL)
    
  {
  }

  void ObjModel::InitGL() { 

    Object::InitGL();

    if(model == NULL) 
    {
      model = glmReadOBJ((char*)modelFileName.c_str());
      glmUnitize(model);
      glmFacetNormals(model);
      glmVertexNormals(model, 90.0);
      glmScale(model, modelScale);
      glmFacetNormals(model);

    }

    
  }
  void ObjModel::DrawModel()   { 

    if(model != NULL) {
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glmDraw(model, GLM_SMOOTH | GLM_MATERIAL);
      glDisable(GL_LIGHTING);
    }

  }


}