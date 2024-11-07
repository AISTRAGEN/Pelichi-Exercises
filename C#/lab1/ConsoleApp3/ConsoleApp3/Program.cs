using System;

class lab1
{
    static void Main()
    {
        Console.Write("Введіть число для обчислення квадратного кореня: ");
        if (double.TryParse(Console.ReadLine(), out double userInput))
        {
            double? result = FindSquareRoot(userInput);
            if (result.HasValue)
            {
                Console.WriteLine($"Квадратний корінь з {userInput} ≈ {result.Value}");
            }
            else
            {
                Console.WriteLine($"Квадратний корінь з {userInput} не може бути обчислений.");
                
            }
        }
        else
        {
            Console.WriteLine("Введено некоректне значення.");
        }
    }

    static double? FindSquareRoot(double number)
    {
        if (number < 0)
        {
            return null; 
        }
        double accuracy = 0.0000000001;  
        double approach = 1.0; 

        while (true)
        {
            double newApproach = 0.5 * (approach + number / approach);
            
            if (Math.Abs(newApproach - approach) < accuracy)
            {
                return newApproach;
            }
            approach = newApproach; 
        }
    }
}