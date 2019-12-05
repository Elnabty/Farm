using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RELAY_MODULE_TEST
{
    static class GlobalClass //allows variables to be passed from form2 to form1
    {
        static private string global_ip = "";
        static private int global_port = 17494;
        static byte global_module = 16; //ethry02 module id

        public static string ipaddress
        {
            get { return global_ip; }
            set { global_ip = value; }
        }

        public static int portnumber
        {
            get { return global_port; }
            set { global_port = value; }
        }

        public static byte module_type
        {
            get { return global_module; }
            set { global_module = value; }
        }

    }
}
