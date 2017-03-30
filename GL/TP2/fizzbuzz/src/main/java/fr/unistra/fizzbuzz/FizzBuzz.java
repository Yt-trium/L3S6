package fr.unistra.fizzbuzz;

public class FizzBuzz {

	public String convert(int number) {
    if(number%3 == 0)
    {
      if(number%5 == 0)
        return "FizzBuzz";
      return "Fizz";
    }
    else if(number%5 == 0)
    {
      return "Buzz";
    }

    StringBuilder sb = new StringBuilder();
    sb.append("");
    sb.append(number);
    String strI = sb.toString();
    return strI;
    // throw new RuntimeException("Not implemented");
	}
}
