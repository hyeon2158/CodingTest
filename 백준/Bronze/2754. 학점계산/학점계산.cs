string ABC = Console.ReadLine();
float score = 'E' - ABC[0];
if (ABC[0] == 'F') score = 0f;
else if (ABC[1] == '+') score += 0.3f;
else if (ABC[1] == '-') score -= 0.3f;
Console.WriteLine($"{score:0.0}");