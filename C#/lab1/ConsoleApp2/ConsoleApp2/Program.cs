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
        // Сортуємо масив за останнім символом кожного елемента в зворотному порядку
        Array.Sort(station, (a, b) => b[b.Length - 1].CompareTo(a[a.Length - 1]));
    }
}