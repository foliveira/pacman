using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace PacMapCreator
{
    public partial class mainForm : Form
    {
        private Button[] map;
        private int size;
        private bool[] positions;

        public mainForm()
        {
            InitializeComponent();
            positions = new bool[2];
        }

        private void generateBtn_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < positions.Length; ++i)
                positions[i] = false;

            if (map != null)
            {
                for (int i = 0; i < map.Length; ++i)
                    map[i].Dispose();
            }

            int sz = size = (int)sizesList.Value;
            
            map = new Button[sz * sz];

            for (int i = 0; i < map.Length; ++i)
            {
                map[i] = new Button();

                map[i].FlatStyle = System.Windows.Forms.FlatStyle.Flat;
                map[i].Location = new System.Drawing.Point(3 + 25 * (i % sz), 3 + 25 * (i / sz));
                map[i].Name = i.ToString();
                map[i].Size = new System.Drawing.Size(25, 25);
                map[i].BackColor = Color.White;
                map[i].MouseDown += new System.Windows.Forms.MouseEventHandler(this.mapButtonAct);
            }

            this.Controls.AddRange(map);

            this.Width = (sz + 1) * 25;
            this.Height = (sz + 1) * 25 + 115;
        }

        private void mapButtonAct(object sender, MouseEventArgs me)
        {
            Button b = (Button)sender;
            int idx = Int32.Parse(b.Name);

            if (me.Button == MouseButtons.Left)
            {
                if (map[idx].BackColor == Color.Red) 
                    positions[0] = false;
                else if(map[idx].BackColor == Color.Green)
                    positions[1] = false;

                map[idx].BackColor = map[idx].BackColor == Color.Black ? Color.White : Color.Black;
            }
            else
            {
                if (map[idx].BackColor != Color.Red && !positions[0])
                {
                    if (map[idx].BackColor == Color.Green)
                        positions[1] = false;

                    map[idx].BackColor = Color.Red;
                    positions[0] = true;
                }
                else if (map[idx].BackColor != Color.Green && !positions[1])
                {
                    if (map[idx].BackColor == Color.Red)
                        positions[0] = false;

                    map[idx].BackColor = Color.Green;
                    positions[1] = true;
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!positions[0] || !positions[1])
            {
                MessageBox.Show("Pacman and Anti-Pacman Start points not defined",
                                    "Error",
                                    MessageBoxButtons.OK,
                                    MessageBoxIcon.Error
                                );
            }
            else
                saveDlg.ShowDialog();
        }

        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            string file = saveDlg.FileName;

            FileInfo fi = new FileInfo(file);

            StreamWriter sw = fi.CreateText();

            sw.Write(size);

            for (int i = 0; i < map.Length; ++i)
            {
                if (i % size == 0)
                    sw.WriteLine();

                if (map[i].BackColor == Color.Black)
                    sw.Write('#');
                else if (map[i].BackColor == Color.Red)
                    sw.Write('S');
                else if (map[i].BackColor == Color.Green)
                    sw.Write('A');
                else
                    sw.Write('-');
            }

            sw.Close();
        }
    }
}
