package fr.unistra.fizzbuzz;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class FizzBuzzJUnitTest {

	private FizzBuzz fizzbuzz = new FizzBuzz();

	@Test
	public void returnsNumberForInputNotDivisibleByThreeAndFive() {
		assertEquals("1", fizzbuzz.convert(1));
		assertEquals("2", fizzbuzz.convert(2));
		assertEquals("4", fizzbuzz.convert(4));
		assertEquals("7", fizzbuzz.convert(7));
		assertEquals("11",fizzbuzz.convert(11));
		assertEquals("13",fizzbuzz.convert(13));
		assertEquals("14",fizzbuzz.convert(14));
	}

  public void returnsNumberForInputDivisibleByThreeOrFive()
  {
		assertEquals("Fizz",fizzbuzz.convert(3));
    assertEquals("Fizz",fizzbuzz.convert(6));
  	assertEquals("Fizz",fizzbuzz.convert(9));
  	assertEquals("Fizz",fizzbuzz.convert(12));
		assertEquals("Buzz",fizzbuzz.convert(5));
		assertEquals("Buzz",fizzbuzz.convert(10));
		assertEquals("FizzBuzz",fizzbuzz.convert(15));
  }
}
