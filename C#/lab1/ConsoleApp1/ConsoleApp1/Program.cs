using System;
using System.Text;

class FirstTask
{
    static void Main(string[] args)
    {
        FirstTask task = new FirstTask();
        char symbol = task.InputSearch();
        task.Searcher(symbol);
        task.PrintStations(); 
    }

    // Масив станцій
    string[] station = { "Київська", "Шевченко", "Курлик", "Харківська", "Кривбас", "Артемівская" };

    public void PrintStations()
    {
        Sorter();
        Console.WriteLine("Відсортирований масив в зворотньому порядку(остання літера)");
        
        for (int i = 0; i < station.Length; i++)
        {
            Console.WriteLine(station[i]);
        }
    }
    public void Searcher(char symbol)
    {
        bool found = false;
        
        // Поиск станций по введенной букве
        for (int i = 0; i < station.Length; i++)
        {
            if (station[i].StartsWith(symbol.ToString(), StringComparison.OrdinalIgnoreCase))
            {
                found = true;
                Console.WriteLine(station[i]);
            }
        }
        if (!found)
        {
            Console.WriteLine("Спробуйте інші букви");
        }
    }

    public char InputSearch()
    {
        Console.WriteLine("Впишіть першу букву вашої станції");
        char symbol = Console.ReadKey().KeyChar;
        Console.WriteLine();
        return symbol;
    }

    public void Sorter()
    {
        
        for (int i = 0; i < station.Length - 1; i++)
        {
            for (int j = i + 1; j < station.Length; j++)
            {
                char lastCharI = station[i][station[i].Length - 1];
                char lastCharJ = station[j][station[j].Length - 1];
                
                if (lastCharI < lastCharJ)
                {
                    string temp = station[i];
                    station[i] = station[j];
                    station[j] = temp;
                }
            }
        }
    }
}
