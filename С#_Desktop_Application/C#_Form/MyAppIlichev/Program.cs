using System.Text;
using System.Runtime.InteropServices;

namespace MyAppIlichev
{

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    struct SportsmanDataStruct
    {
        [MarshalAs(UnmanagedType.I1)]
        public bool is_footballer;

        [MarshalAs(UnmanagedType.I4)]
        public int id;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 100)]
        public string surname;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 100)]
        public string name;
        [MarshalAs(UnmanagedType.I4)]
        public int age;
        [MarshalAs(UnmanagedType.I4)]
        public int height;
        [MarshalAs(UnmanagedType.I4)]
        public int number;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 100)]
        public string position;
    }

    internal static class Program
    {


        [DllImport("SG.dll")]
        public static extern int GetGroupSize(StringBuilder filename);

        [DllImport("SG.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Load(StringBuilder filename, [Out] SportsmanDataStruct[] sportsmans);

        [DllImport("SG.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Save(StringBuilder filename, SportsmanDataStruct[] sportsmans, int size);

        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        /// 
        [STAThread]
        static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Application.Run(new Form());
        }
    }
}