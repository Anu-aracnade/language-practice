function fizzBuzz(num1) {
    if (num1 % 5 === 0 && num1 % 3 === 0)
        return "FizzBuzz";
    else if (num1 % 3 === 0)
        return "Fizz";
    else if (num1 % 5 === 0)
        return "Buzz";
    else
        return num1;
}
console.log(fizzBuzz(30));