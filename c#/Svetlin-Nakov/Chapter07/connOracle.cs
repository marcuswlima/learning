using System;
using System.Data;
using Oracle.ManagedDataAccess.Client;

namespace ODP.NET_Framework_Get_Started
{
    class GettingStarted
    {
        //Prerequisite: This app assumes the user has already been created with the
        // necessary privileges
        //Set the demo user id, such as DEMODOTNET and password
        public static string user = "<DEMODOTNET>";
        public static string pwd = "<PASSWORD>";

        //Set the net service name, Easy Connect, or connect descriptor of the pluggable DB, 
        // such as "localhost/XEPDB1" for 18c XE or higher
        public static string db = "<localhost/XEPDB1>";

        static void Main()
        {
            string conStringUser = "User Id=" + user + ";Password=" + pwd + ";Data Source=" + db + ";";

            using (OracleConnection con = new OracleConnection(conStringUser))
            {
                using (OracleCommand cmd = con.CreateCommand())
                {
                    try
                    {
                        con.Open();
                        Console.WriteLine("Successfully connected to Oracle Database as " + user);
                        Console.WriteLine();

                        //Retrieve sample data
                        cmd.CommandText = "SELECT description, done FROM todoitem";
                        OracleDataReader reader = cmd.ExecuteReader();
                        while (reader.Read())
                        {
                            if (reader.GetBoolean(1))
                                Console.WriteLine(reader.GetString(0) + " is done.");
                            else
                                Console.WriteLine(reader.GetString(0) + " is NOT done.");
                        }

                      
                        reader.Dispose();
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }
                }
            }
        }
    }
}