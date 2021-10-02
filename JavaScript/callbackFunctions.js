// Question: write your own function which takes a callback

// Write a function which takes
// 1. Your name
// 2. A function which it will call with the length of your name

// Now, call this function with the two parameters.
// 1. Your name. This is simple.
// 2. A function. This function will get the length of the string. Use that length to print a message: `OMG! my name is X char long!`

const strLength = (name, func) => {
  const nameLength = name.length;
  func(nameLength);
};
strLength("Priyanshu", (nL) => {
  console.log(`Oh, my name is ${nL} char long.`);
});

// Output: Oh, my name is 9 char long.
