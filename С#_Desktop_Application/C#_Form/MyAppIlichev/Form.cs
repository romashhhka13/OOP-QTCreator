using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace MyAppIlichev
{
    public partial class Form : System.Windows.Forms.Form
    {

        private SportsmanGroup SG { get; set; } = new SportsmanGroup();

        public Form()
        {
            InitializeComponent();
            this.Text = "Ильичев Роман АС-22-05";
            textBox5.Hide();
            textBox6.Hide();
            label5.Hide();
            label6.Hide();
            textBox1.TextChanged -= textBox1_TextChanged;
            textBox2.TextChanged -= textBox1_TextChanged;
            textBox3.TextChanged -= textBox1_TextChanged;
            textBox4.TextChanged -= textBox1_TextChanged;
            textBox5.TextChanged -= textBox1_TextChanged;
            textBox6.TextChanged -= textBox1_TextChanged;
            delete_button.Enabled = false;
            textBox1.Enabled = false;
            textBox2.Enabled = false;
            textBox3.Enabled = false;
            textBox4.Enabled = false;
            textBox5.Enabled = false;
            textBox6.Enabled = false;
            radioButton1.Checked = true;
            radioButton2.Checked = false;
        }

        private void Form_Load(object sender, EventArgs e) { }

        private void OpenMenuClick(object sender, EventArgs e)
        {

            string path = Path.Combine(Directory.GetCurrentDirectory());

            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.InitialDirectory = path;
                openFileDialog.Filter = "Файл (*.txt)|*.txt";

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    var sb = new StringBuilder(openFileDialog.FileName);
                    int size = Program.GetGroupSize(sb);
                    if (size == 0)
                    {
                        MessageBox.Show("Файл пуст!", $"Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                        return;
                    }

                    SportsmanDataStruct[] structs_array = new SportsmanDataStruct[size];
                    Program.Load(sb, structs_array);

                    SG.Clear();
                    listBox1.Items.Clear();
                    foreach (var item in structs_array)
                    {
                        SG.AddStruct(item);
                        listBox1.Items.Add($"{item.surname} {item.name}");
                    }

                    listBox1.SelectedIndex = 0;
                    textBox1.TextChanged += textBox1_TextChanged;
                    textBox2.TextChanged += textBox1_TextChanged;
                    textBox3.TextChanged += textBox1_TextChanged;
                    textBox4.TextChanged += textBox1_TextChanged;
                    textBox5.TextChanged += textBox1_TextChanged;
                    textBox6.TextChanged += textBox1_TextChanged;
                    textBox1.Enabled = true;
                    textBox2.Enabled = true;
                    textBox3.Enabled = true;
                    textBox4.Enabled = true;
                    textBox5.Enabled = true;
                    textBox6.Enabled = true;
                    delete_button.Enabled = true;

                }
            }
        }

        private void SaveAsMenuClick(object sender, EventArgs e)
        {
            string path = Path.Combine(Directory.GetCurrentDirectory(), "../");

            using (SaveFileDialog saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.Title = "Сохранить как";
                saveFileDialog.Filter = "Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";
                saveFileDialog.InitialDirectory = Path.GetFullPath(path);

                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    var sb = new StringBuilder(saveFileDialog.FileName);
                    SportsmanDataStruct[] sportsmans = SG.GetStructs();
                    Program.Save(sb, sportsmans, sportsmans.Length);
                }
            }
        }

        private void ClearMenuClick(object sender, EventArgs e)
        {

            SG.Clear();
            listBox1.Items.Clear();
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
            textBox5.Hide();
            textBox6.Hide();
            label5.Hide();
            label6.Hide();

            textBox1.TextChanged -= textBox1_TextChanged;
            textBox2.TextChanged -= textBox1_TextChanged;
            textBox3.TextChanged -= textBox1_TextChanged;
            textBox4.TextChanged -= textBox1_TextChanged;
            textBox5.TextChanged -= textBox1_TextChanged;
            textBox6.TextChanged -= textBox1_TextChanged;
            textBox1.Enabled = false;
            textBox2.Enabled = false;
            textBox3.Enabled = false;
            textBox4.Enabled = false;
            textBox5.Enabled = false;
            textBox6.Enabled = false;
            delete_button.Enabled = false;

            MessageBox.Show("Данные очищены!", "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void QuitMenuClick(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void add_button_click(object sender, EventArgs e)
        {
            int index;

            if (radioButton1.Checked)
            {
                //MessageBox.Show("Недопустимое значение!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                textBox5.Text = "";
                textBox6.Text = "";
                textBox5.Hide();
                textBox6.Hide();
                label5.Hide();
                label6.Hide();
                index = SG.AddSportsman();
            }
            else
            {
                textBox5.Show();
                textBox6.Show();
                label5.Show();
                label6.Show();
                index = SG.AddFootballer();
                
            }

            listBox1.Items.Add($"{SG.group[index].Surname} {SG.group[index].Name}");
            listBox1.SelectedIndex = index;
            textBox1.Enabled = true;
            textBox2.Enabled = true;
            textBox3.Enabled = true;
            textBox4.Enabled = true;
            textBox5.Enabled = true;
            textBox6.Enabled = true;

            if (listBox1.Items.Count == 1)
            {
                textBox1.TextChanged += textBox1_TextChanged;
                textBox2.TextChanged += textBox1_TextChanged;
                textBox3.TextChanged += textBox1_TextChanged;
                textBox4.TextChanged += textBox1_TextChanged;
                textBox5.TextChanged += textBox1_TextChanged;
                textBox6.TextChanged += textBox1_TextChanged;
                textBox1.Enabled = true;
                textBox2.Enabled = true;
                textBox3.Enabled = true;
                textBox4.Enabled = true;
                textBox5.Enabled = true;
                textBox6.Enabled = true;
                delete_button.Enabled = true;

            }
        }

        private void delete_button_click(object sender, EventArgs e)
        {

            int selectedIndex = listBox1.SelectedIndex;
            if (selectedIndex >= 0 && selectedIndex < listBox1.Items.Count)
            {
                SG.DeleteSportsman(selectedIndex);
                listBox1.Items.RemoveAt(selectedIndex);
                listBox1.SelectedIndex = (selectedIndex == listBox1.Items.Count) ? selectedIndex - 1 : selectedIndex;
            }

            if (listBox1.Items.Count == 0)
            {
                textBox1.TextChanged -= textBox1_TextChanged;
                textBox2.TextChanged -= textBox1_TextChanged;
                textBox3.TextChanged -= textBox1_TextChanged;
                textBox4.TextChanged -= textBox1_TextChanged;
                textBox5.TextChanged -= textBox1_TextChanged;
                textBox6.TextChanged -= textBox1_TextChanged;
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
                textBox4.Enabled = false;
                textBox5.Enabled = false;
                textBox6.Enabled = false;
                textBox1.Text = "";
                textBox2.Text = "";
                textBox3.Text = "";
                textBox4.Text = "";
                textBox5.Text = "";
                textBox6.Text = "";
                textBox5.Hide();
                textBox6.Hide();
                label5.Hide();
                label6.Hide();
                delete_button.Enabled = false;
            }
        }

        private void listBox1_selected_index_changed(object sender, EventArgs e)
        {
            int selectedIndex = listBox1.SelectedIndex;
            if (selectedIndex == -1 && listBox1.SelectedIndex < listBox1.Items.Count)
            {
                return;
            }

            //if (selectedIndex >= 0 && listBox1.SelectedIndex < listBox1.Items.Count)
            List<string> data = SG.GetData(selectedIndex);

            textBox1.Text = data[0];
            textBox2.Text = data[1];
            textBox3.Text = data[2] != "0" ? data[2] : "";
            textBox4.Text = data[3] != "0" ? data[3] : "";

            if (SG.isFootballer(selectedIndex))
            {
                textBox5.Text = data[4] != "0" ? data[4] : "";
                textBox6.Text = data[5];
                textBox5.Show();
                textBox6.Show();
                label5.Show();
                label6.Show();
            }
            else
            {
                textBox5.Hide();
                textBox6.Hide();
                label5.Hide();
                label6.Hide();
            }


        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            int selectedIndex = listBox1.SelectedIndex;
            if (selectedIndex == -1)
            {
                return;
            }

            SG.group[selectedIndex].Surname = textBox1.Text;
            listBox1.Items[selectedIndex] = $"{textBox1.Text} {textBox2.Text}";
            listBox1.Refresh();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            int selectedIndex = listBox1.SelectedIndex;
            if (selectedIndex == -1)
            {
                return;
            }

            SG.group[selectedIndex].Name = textBox2.Text;
            listBox1.Items[selectedIndex] = $"{textBox1.Text} {textBox2.Text}";
            listBox1.Refresh();
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            int selectedIndex = listBox1.SelectedIndex;
            if (selectedIndex == -1)
            {
                return;
            }

            int age;

            if (int.TryParse(textBox3.Text, out age))
            {
                SG.group[selectedIndex].Age = age;
            }
            else if (textBox3.Text == "")
            {
                SG.group[selectedIndex].Age = 0;
                textBox3.Text = "";
            }
            else
            {
                SG.group[selectedIndex].Age = 0;
                textBox3.Text = "";
                MessageBox.Show("Недопустимое значение!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            int selectedIndex = listBox1.SelectedIndex;
            if (selectedIndex == -1)
            {
                return;
            }

            int height;

            if (int.TryParse(textBox4.Text, out height))
            {
                SG.group[selectedIndex].Height = height;
            }
            else if (textBox4.Text == "")
            {
                SG.group[selectedIndex].Age = 0;
            }
            else
            {
                SG.group[selectedIndex].Height = 0;
                MessageBox.Show("Недопустимое значение!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            int selectedIndex = listBox1.SelectedIndex;
            if (selectedIndex == -1)
            {
                return;
            }

            if (SG.group[selectedIndex] is Footballer footballer)
            {

                int number;

                if (int.TryParse(textBox5.Text, out number))
                {
                    footballer.Number = number;
                }
                else if (textBox5.Text == "")
                {
                    footballer.Number = 0;
                    textBox5.Text = "";
                }
                else
                {
                    footballer.Number = 0;
                    MessageBox.Show("Недопустимое значение!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }


        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {
            int selectedIndex = listBox1.SelectedIndex;
            if (selectedIndex == -1)
            {
                return;
            }
            if (SG.group[selectedIndex] is Footballer footballer)
            {
                footballer.Position = textBox6.Text;
            }
        }

        private void rb1_checked_changed(object sender, EventArgs e)
        {

        }

        private void rb2_checked_changed(object sender, EventArgs e)
        {

        }
    }
}
