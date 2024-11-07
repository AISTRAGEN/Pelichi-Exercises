using System;

class ThirdTask
{
    static void Main(string[] args)
    {
        int firstNumber;  
        int secondNumber; 

        Console.WriteLine("Впишіть перше число");
        int.TryParse(Console.ReadLine(), out firstNumber);

        Console.WriteLine("Впишіть друге число");
        int.TryParse(Console.ReadLine(), out secondNumber);

        while (firstNumber != 0 && secondNumber != 0)
        {
            if (firstNumber > secondNumber)
            {
                firstNumber = firstNumber % secondNumber;
            }
            else
            {
                secondNumber = secondNumber % firstNumber;
            }
        }
        int gcd = firstNumber + secondNumber;
        Console.WriteLine("Найбільший спільний ділник це\n" + gcd);
    }
}