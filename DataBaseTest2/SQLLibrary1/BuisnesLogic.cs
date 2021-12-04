using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;

namespace SQLLibrary1
{
    public class BuisnesLogic
    {
        DataBase database = new DataBase();

        private MySqlCommand command = new MySqlCommand();
        private string sql = "";
        private int count;

        private int CountBD(MySqlConnection mySqlConnection)
        {
            sql = "SELECT MAX(idusers) FROM users";
            command.Connection = mySqlConnection;
            command.CommandText = sql;
            string countStr = command.ExecuteScalar().ToString();

            count = int.Parse(countStr);

            return count;
        }


        public void WriteName(MySqlConnection conn)
        {
            Console.WriteLine("Введите id");
            string id = Console.ReadLine();
            sql = "SELECT name FROM users WHERE idusers = " + id;
            command.Connection = conn;
            command.CommandText = sql;

            string name = command.ExecuteScalar().ToString();

            Console.WriteLine(name);
        }

        public void ShowBaseDate(MySqlConnection mySqlConnection)
        {
            sql = "SELECT *FROM users";
            command.Connection = mySqlConnection;
            command.CommandText = sql;
            MySqlDataReader reader = command.ExecuteReader();

            while (reader.Read())
            {
                Console.WriteLine(reader[0].ToString() + " " + reader[1].ToString() + " " + reader[2].ToString());

            }
            reader.Close();
        }

        public void AddNote(MySqlConnection mySqlConnection)
        {
            int orderInt = CountBD(mySqlConnection)+1;

            string orderStr = orderInt.ToString();

            Console.WriteLine("Введите имя и возраст с новой строки");
            string name = Console.ReadLine();
            string age = Console.ReadLine();
            sql = "INSERT INTO users (idusers, name, age) VALUES (" + orderStr + ",'" + name + "'," + age + ")";
            command.Connection = mySqlConnection;
            command.CommandText = sql;
            try
            {
                command.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        public void UpdateDB(MySqlConnection mySqlConnection)
        {
            Console.Clear();
            ShowBaseDate(mySqlConnection);
            Console.WriteLine("\n");
            Console.WriteLine("Введите Id элемента для изменения имени и возраста");
            string id = Console.ReadLine();
            Console.WriteLine("Введите новые значения");
            string name = Console.ReadLine();
            string age = Console.ReadLine();
            string sql = "UPDATE users SET name = '"+name+"', age = "+age+" WHERE idusers = "+id;
            command.Connection = mySqlConnection;
            command.CommandText = sql;
            try
            {
                command.ExecuteNonQuery();
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
        
        public void DeleteDB(MySqlConnection mySqlConnection)
        {
            Console.Clear();
            ShowBaseDate(mySqlConnection);
            Console.WriteLine("Введите id для удаления");
            string id = Console.ReadLine();
            sql = "DELETE FROM users WHERE idusers = " + id;
            command.Connection = mySqlConnection;
            command.CommandText = sql;
            try
            {
                command.ExecuteNonQuery();
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
      
        }


       
    }
}

