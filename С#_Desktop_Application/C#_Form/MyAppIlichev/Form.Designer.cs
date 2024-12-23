namespace MyAppIlichev
{
    partial class Form
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            listBox1 = new ListBox();
            menuStrip1 = new MenuStrip();
            FileToolStripMenuItem = new ToolStripMenuItem();
            OpenToolStripMenuItem = new ToolStripMenuItem();
            SaveAsКакToolStripMenuItem1 = new ToolStripMenuItem();
            ClearКакToolStripMenuItem = new ToolStripMenuItem();
            QuitToolStripMenuItem = new ToolStripMenuItem();
            add_button = new Button();
            delete_button = new Button();
            backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            label1 = new Label();
            textBox1 = new TextBox();
            label2 = new Label();
            textBox2 = new TextBox();
            label3 = new Label();
            textBox3 = new TextBox();
            label4 = new Label();
            textBox4 = new TextBox();
            label5 = new Label();
            textBox5 = new TextBox();
            label6 = new Label();
            textBox6 = new TextBox();
            tableLayoutPanel1 = new TableLayoutPanel();
            radioButton1 = new RadioButton();
            radioButton2 = new RadioButton();
            menuStrip1.SuspendLayout();
            tableLayoutPanel1.SuspendLayout();
            SuspendLayout();
            // 
            // listBox1
            // 
            listBox1.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            listBox1.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            listBox1.FormattingEnabled = true;
            listBox1.HorizontalScrollbar = true;
            listBox1.ItemHeight = 21;
            listBox1.Location = new Point(6, 31);
            listBox1.Margin = new Padding(0);
            listBox1.MaximumSize = new Size(312, 1000);
            listBox1.MinimumSize = new Size(200, 300);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(312, 403);
            listBox1.TabIndex = 0;
            listBox1.SelectedIndexChanged += listBox1_selected_index_changed;
            // 
            // menuStrip1
            // 
            menuStrip1.Font = new Font("Segoe UI", 9.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            menuStrip1.Items.AddRange(new ToolStripItem[] { FileToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(800, 25);
            menuStrip1.TabIndex = 1;
            menuStrip1.Text = "menuStrip1";
            // 
            // FileToolStripMenuItem
            // 
            FileToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { OpenToolStripMenuItem, SaveAsКакToolStripMenuItem1, ClearКакToolStripMenuItem, QuitToolStripMenuItem });
            FileToolStripMenuItem.Name = "FileToolStripMenuItem";
            FileToolStripMenuItem.Size = new Size(39, 21);
            FileToolStripMenuItem.Text = "File";
            // 
            // OpenToolStripMenuItem
            // 
            OpenToolStripMenuItem.Name = "OpenToolStripMenuItem";
            OpenToolStripMenuItem.Size = new Size(117, 22);
            OpenToolStripMenuItem.Text = "Open";
            OpenToolStripMenuItem.Click += OpenMenuClick;
            // 
            // SaveAsКакToolStripMenuItem1
            // 
            SaveAsКакToolStripMenuItem1.Name = "SaveAsКакToolStripMenuItem1";
            SaveAsКакToolStripMenuItem1.Size = new Size(117, 22);
            SaveAsКакToolStripMenuItem1.Text = "SaveAs";
            SaveAsКакToolStripMenuItem1.Click += SaveAsMenuClick;
            // 
            // ClearКакToolStripMenuItem
            // 
            ClearКакToolStripMenuItem.Name = "ClearКакToolStripMenuItem";
            ClearКакToolStripMenuItem.Size = new Size(117, 22);
            ClearКакToolStripMenuItem.Text = "Clear";
            ClearКакToolStripMenuItem.Click += ClearMenuClick;
            // 
            // QuitToolStripMenuItem
            // 
            QuitToolStripMenuItem.Name = "QuitToolStripMenuItem";
            QuitToolStripMenuItem.Size = new Size(117, 22);
            QuitToolStripMenuItem.Text = "Quit";
            QuitToolStripMenuItem.Click += QuitMenuClick;
            // 
            // add_button
            // 
            add_button.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            add_button.AutoSize = true;
            add_button.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            add_button.Location = new Point(3, 3);
            add_button.Name = "add_button";
            add_button.Size = new Size(134, 31);
            add_button.TabIndex = 2;
            add_button.Text = "Добавить";
            add_button.UseVisualStyleBackColor = true;
            add_button.Click += add_button_click;
            // 
            // delete_button
            // 
            delete_button.AutoSize = true;
            delete_button.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            delete_button.Location = new Point(143, 3);
            delete_button.Name = "delete_button";
            delete_button.Size = new Size(135, 31);
            delete_button.TabIndex = 2;
            delete_button.Text = "Удалить";
            delete_button.UseVisualStyleBackColor = true;
            delete_button.Click += delete_button_click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label1.Location = new Point(320, 33);
            label1.MinimumSize = new Size(82, 21);
            label1.Name = "label1";
            label1.Size = new Size(82, 21);
            label1.TabIndex = 3;
            label1.Text = "Фамилия: ";
            // 
            // textBox1
            // 
            textBox1.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            textBox1.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            textBox1.Location = new Point(406, 29);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(390, 29);
            textBox1.TabIndex = 4;
            textBox1.TextChanged += textBox1_TextChanged;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label2.Location = new Point(320, 68);
            label2.Name = "label2";
            label2.Size = new Size(48, 21);
            label2.TabIndex = 3;
            label2.Text = "Имя: ";
            // 
            // textBox2
            // 
            textBox2.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            textBox2.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            textBox2.Location = new Point(406, 64);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(390, 29);
            textBox2.TabIndex = 4;
            textBox2.TextChanged += textBox2_TextChanged;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label3.Location = new Point(320, 103);
            label3.Name = "label3";
            label3.Size = new Size(73, 21);
            label3.TabIndex = 3;
            label3.Text = "Возраст: ";
            // 
            // textBox3
            // 
            textBox3.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            textBox3.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            textBox3.Location = new Point(406, 99);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(390, 29);
            textBox3.TabIndex = 4;
            textBox3.TextChanged += textBox3_TextChanged;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label4.Location = new Point(320, 138);
            label4.Name = "label4";
            label4.Size = new Size(49, 21);
            label4.TabIndex = 3;
            label4.Text = "Рост: ";
            // 
            // textBox4
            // 
            textBox4.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            textBox4.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            textBox4.Location = new Point(406, 134);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(390, 29);
            textBox4.TabIndex = 4;
            textBox4.TextChanged += textBox4_TextChanged;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label5.Location = new Point(320, 173);
            label5.Name = "label5";
            label5.Size = new Size(65, 21);
            label5.TabIndex = 3;
            label5.Text = "Номер: ";
            // 
            // textBox5
            // 
            textBox5.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            textBox5.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            textBox5.Location = new Point(406, 169);
            textBox5.Name = "textBox5";
            textBox5.Size = new Size(390, 29);
            textBox5.TabIndex = 4;
            textBox5.TextChanged += textBox5_TextChanged;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label6.Location = new Point(320, 208);
            label6.Name = "label6";
            label6.Size = new Size(80, 21);
            label6.TabIndex = 3;
            label6.Text = "Позиция: ";
            // 
            // textBox6
            // 
            textBox6.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            textBox6.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            textBox6.Location = new Point(406, 204);
            textBox6.Name = "textBox6";
            textBox6.Size = new Size(390, 29);
            textBox6.TabIndex = 4;
            textBox6.TextChanged += textBox6_TextChanged;
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            tableLayoutPanel1.ColumnCount = 2;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.Controls.Add(add_button, 0, 0);
            tableLayoutPanel1.Controls.Add(delete_button, 1, 0);
            tableLayoutPanel1.Location = new Point(426, 393);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 1;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 50F));
            tableLayoutPanel1.Size = new Size(281, 39);
            tableLayoutPanel1.TabIndex = 5;
            // 
            // radioButton1
            // 
            radioButton1.AutoSize = true;
            radioButton1.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            radioButton1.Location = new Point(426, 307);
            radioButton1.Name = "radioButton1";
            radioButton1.Size = new Size(107, 25);
            radioButton1.TabIndex = 6;
            radioButton1.TabStop = true;
            radioButton1.Text = "Спортсмен";
            radioButton1.UseVisualStyleBackColor = true;
            radioButton1.CheckedChanged += rb1_checked_changed;
            // 
            // radioButton2
            // 
            radioButton2.AutoSize = true;
            radioButton2.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            radioButton2.Location = new Point(603, 307);
            radioButton2.Name = "radioButton2";
            radioButton2.Size = new Size(104, 25);
            radioButton2.TabIndex = 6;
            radioButton2.TabStop = true;
            radioButton2.Text = "Футболист";
            radioButton2.UseVisualStyleBackColor = true;
            radioButton2.CheckedChanged += rb2_checked_changed;
            // 
            // Form
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.Control;
            ClientSize = new Size(800, 443);
            Controls.Add(radioButton2);
            Controls.Add(radioButton1);
            Controls.Add(tableLayoutPanel1);
            Controls.Add(textBox6);
            Controls.Add(label6);
            Controls.Add(textBox5);
            Controls.Add(label5);
            Controls.Add(textBox4);
            Controls.Add(label4);
            Controls.Add(textBox3);
            Controls.Add(label3);
            Controls.Add(textBox2);
            Controls.Add(label2);
            Controls.Add(textBox1);
            Controls.Add(label1);
            Controls.Add(listBox1);
            Controls.Add(menuStrip1);
            MainMenuStrip = menuStrip1;
            Name = "Form";
            Text = "Form1";
            Load += Form_Load;
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            tableLayoutPanel1.ResumeLayout(false);
            tableLayoutPanel1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListBox listBox1;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem FileToolStripMenuItem;
        private ToolStripMenuItem OpenToolStripMenuItem;
        private ToolStripMenuItem SaveAsКакToolStripMenuItem1;
        private ToolStripMenuItem ClearКакToolStripMenuItem;
        private ToolStripMenuItem QuitToolStripMenuItem;
        private Button add_button;
        private Button delete_button;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private Label label1;
        private TextBox textBox1;
        private Label label2;
        private TextBox textBox2;
        private Label label3;
        private TextBox textBox3;
        private Label label4;
        private TextBox textBox4;
        private Label label5;
        private TextBox textBox5;
        private Label label6;
        private TextBox textBox6;
        private TableLayoutPanel tableLayoutPanel1;
        private RadioButton radioButton1;
        private RadioButton radioButton2;
    }
}
