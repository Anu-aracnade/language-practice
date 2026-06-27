let a = 1;
let b = '1';

console.log(a==b);// loose equality: convert the datatypes ,and check for the main value , different data-types don't matter.
                  // in loose equality java-script perform type coertion to convert to similar datatypes and then compare.
console.log(a===b); // strict equality: also check for the data-type equality.