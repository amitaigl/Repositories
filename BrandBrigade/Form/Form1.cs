using System.Windows.Forms;
//using Bridge; // Assuming reference to C++/CLI project
//using System;

using BrandBrigade;

namespace AppForm
{
    public partial class Form1 : Form
    {
        //private MyCppCliWrapper wrapper = new MyCppCliWrapper(); // !!!!!!!!!!!!!
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Amitai();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                // Get the selected file path
                string filePath = openFileDialog1.FileName;

                // Process the selected file (e.g., read its contents)
                // ...
                //wrapper.OpenFile(filePath); // Call C++/CLI function
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            /*
             // ����� ���� �����
            VideoCapture videoCapture = new VideoCapture("video.mp4");

            // ����� �� ����� ����� ������
            if (videoCapture.IsOpened)
            {
                // ����� ������ ������� �������
                while (true)
                {
                    // ����� ����� �������
                    Mat frame = new Mat();
                    videoCapture.Read(frame);

                    // ����� �� ������ ���� ������
                    if (frame.Data != null)
                    {
                        // ���� ������ ������
                        Image image = frame.ToImage();

                        // ���� ������ �-PictureBox
                        pictureBox1.Image = image;

                        // ����� ���� ����� ������ ���
                        Application.DoEvents();
                    }
                    else
                    {
                        // ���� ������ �� ��� ��� �������
                        break;
                    }
                }

                // ����� ������
                videoCapture.Release();
            }
            else
            {
                // ���� ����� ����� �� �����
                MessageBox.Show("Failed to open video file.");
            }
            */
        }

        private void openFileDialog1_FileOk(object sender, System.ComponentModel.CancelEventArgs e)
        {

        }
    }
}
