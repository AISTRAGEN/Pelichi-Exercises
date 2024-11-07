using System;

class Program
{
    static void Main(string[] args)
    {
        // 1. Ініціалізація звичайного двовимірного масиву
        int[,] array = 
        {
            { 4, 77, 3 },
            { 8, 11, 12 },
            { 17, 24, 9 }
        };
        
        int rowCount = array.GetLength(0); 
        int[][] unevenArray = new int[rowCount][]; 
        
        for (int i = 0; i < rowCount; i++)
        {
            // Рахую тут кількість парних чисел у поточному рядку
            int evenCount = 0;
            for (int j = 0; j < array.GetLength(1); j++)
            {
                if (array[i, j] % 2 == 0)
                {
                    evenCount++;
                }
            }

            // Роблю масив для збереження парних чисел цього рядка
            unevenArray[i] = new int[evenCount];
            int index = 0;

            // Записую парні числа в цей масив
            for (int j = 0; j < array.GetLength(1); j++)
            {
                if (array[i, j] % 2 == 0)
                {
                    unevenArray[i][index++] = array[i, j];
                }
            }
        }

        // 4. Виведення результату
        Console.WriteLine("Невирівняний масив з парними елементами:");
        for (int i = 0; i < rowCount; i++)
        {
            // Виводимо кожен рядок невирівняного масиву
            if (unevenArray[i].Length > 0)
            {
                foreach (var num in unevenArray[i])
                {
                    Console.Write(num + " ");
                }
                Console.WriteLine();
            }
            else
            {
                // Якщо в рядку немає парних чисел
                Console.WriteLine("Немає парних чисел у рядку.");
            }
        }
    }
}
