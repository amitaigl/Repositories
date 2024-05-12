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
             // פתיחת קובץ וידאו
            VideoCapture videoCapture = new VideoCapture("video.mp4");

            // בדיקה אם פתיחת הקובץ הצליחה
            if (videoCapture.IsOpened)
            {
                // לולאה לקריאת פריימים מהסרטון
                while (true)
                {
                    // קריאת פריים מהסרטון
                    Mat frame = new Mat();
                    videoCapture.Read(frame);

                    // בדיקה אם הפריים נקרא בהצלחה
                    if (frame.Data != null)
                    {
                        // המרת הפריים לתמונה
                        Image image = frame.ToImage();

                        // הצגת התמונה ב-PictureBox
                        pictureBox1.Image = image;

                        // המתנה לפני קריאת הפריים הבא
                        Application.DoEvents();
                    }
                    else
                    {
                        // סיום הלולאה אם אין עוד פריימים
                        break;
                    }
                }

                // שחרור משאבים
                videoCapture.Release();
            }
            else
            {
                // הצגת הודעה במקרה של שגיאה
                MessageBox.Show("Failed to open video file.");
            }
            */
        }
    }
}
