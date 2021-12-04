using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;
using SQLLibrary1;

namespace DataBaseTest2
{
    class Program
    {
         DataBase dataBase = new DataBase();
        static void Main(string[] args)
        {
           
            DataBase dataBase = new DataBase();
            
            BuisnesLogic buisnesLogic = new BuisnesLogic();
            try
            {
                dataBase.openConnection();
                Console.WriteLine("Соединение открыто");
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
            buisnesLogic.DeleteDB(dataBase.getConection());
            buisnesLogic.UpdateDB(dataBase.getConection());
            buisnesLogic.ShowBaseDate(dataBase.getConection());
           
            buisnesLogic.AddNote(dataBase.getConection());
            buisnesLogic.WriteName(dataBase.getConection());

            dataBase.closeConnection();
            Console.WriteLine("Соединение разорвано");

            
            Console.ReadLine();
        }
    }
}
