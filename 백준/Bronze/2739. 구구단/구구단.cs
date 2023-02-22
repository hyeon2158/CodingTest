using System;
class Program
{
    static void Main(string[] args)
    {
        string num = Console.ReadLine();
        int ans = int.Parse(num);
        for(int i = 1; i <= 9; i++)
        {
            Console.WriteLine(ans + " * " + i + " = " + (ans * i));
        }
    }
}