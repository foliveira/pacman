/***************************************************************
 * Tipo que representa um modelo Obj (Wavefront OBJ).
 * 
 *
 * --------------------------------------------------------------------------------
 * Instituto Superior de Engenharia de Lisboa
 * Departamento de Engenharia de Electrónica e Telecomunicações e de Computadores
 * Licenciatura em Engenharia Informática e de Computadores
 * Computação Gráfica
 *
 * (c) Carlos Guedes e José Branco - Novembro de 2007
 **********************************************************************************/

#ifndef _OBJ_MODEL_H_
#define _OBJ_MODEL_H_

#include <cggl/Object.h>
#include <string>
#include "glm.h"

namespace cggl {

  class ObjModel : public cggl::Object {

  protected:
    std::string modelFileName;
    float modelScale;
    GLMmodel *model;

  public:
    ObjModel(char *_modelFileName, float modelScale = 1.0f);

    void InitGL();
    void DrawModel();

  };

}

#endif