using System;
using System.Collections.Generic;
using System.IO;

namespace MyLibrary
{
    public static class FileDB
    {
        private static string path;
        public static string FilesPath
        {
            get
            {
                return path;
            }
            set
            {
                path = value ?? throw new Exception("incorrect path");
            }
        }

        public static List<T> GetDataFromFile<T>() where T : IEntity, new()
        {
            string path = FilesPath + "\\" + new T().GetFileName();
            List<T> res = new List<T>();

            using (StreamReader sr = new StreamReader(path))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    T item = new T();
                    item.Initialize(line);
                    res.Add(item);
                }
            }

            return res;
        }

        public static T GetEntityById<T>(int id) where T : IEntity, new()
        {
            string path = FilesPath + "\\" + new T().GetFileName();
            T res = new T();

            using (StreamReader sr = new StreamReader(path))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    string strId = line.Split(';')[0];
                    if (strId == Convert.ToString(id))
                    {
                        res.Initialize(line);
                        return res;
                    }
                }
            }

            return res;
        }

        public static void Delete<T>(T item) where T : IEntity, new()
        {
            string filePath = FilesPath + "\\" + item.GetFileName();
            string strId = item.GetId().ToString();
            string tempFilePath = Path.GetTempFileName();

            using (StreamReader sr = new StreamReader(filePath))
            using (StreamWriter sw = new StreamWriter(tempFilePath))
            {
                string line;

                while ((line = sr.ReadLine()) != null)
                {
                    string currId = line.Split(';')[0];
                    if (!currId.Equals(strId))
                    {
                        sw.WriteLine(line);
                    }
                }
            }

            File.Delete(filePath);
            File.Move(tempFilePath, filePath);
        }

        public static void Update<T>(T item) where T : IEntity, new()
        {
            string filePath = FilesPath + "\\" + item.GetFileName();
            string strId = item.GetId().ToString();
            string tempFilePath = Path.GetTempFileName();

            using (StreamReader sr = new StreamReader(filePath))
            using (StreamWriter sw = new StreamWriter(tempFilePath, true))
            {
                string line;

                while ((line = sr.ReadLine()) != null)
                {
                    string currId = line.Split(';')[0];

                    if (currId.Equals(strId))
                    {
                        sw.WriteLine(item.GetFileStr());
                        continue;
                    }

                    sw.WriteLine(line);
                }
            }

            File.Delete(filePath);
            File.Move(tempFilePath, filePath);
        }

        public static void Create<T>(T item) where T : IEntity, new()
        {
            string filePath = FilesPath + "\\" + item.GetFileName();
            int lastId = 0;

            using (StreamReader sr = new StreamReader(filePath))
            {
                string strId = "0";
                string line;

                while ((line = sr.ReadLine()) != null)
                {
                    strId = line.Split(';')[0];
                }

                lastId = Convert.ToInt32(strId);
            }

            using (StreamWriter sw = new StreamWriter(filePath, true))
            {
                item.SetId(lastId + 1);

                sw.WriteLine(item.GetFileStr());
            }
        }
    }
}
