namespace AppForm
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {

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
    }
}
