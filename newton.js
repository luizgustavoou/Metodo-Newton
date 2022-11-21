const MAX = 101;
const fa_str = "0.9-(1+x+x²/2)*e^(-x)";
const fb_str = "0.1-(1+x+x²/2)*e^(-x)";
const { abs, e, pow, round } = require("mathjs");

function fa(x) {
  return 0.9 - (1 + x + (x * x) / 2) * pow(e, -x);
}

function dfa(x) {
  return (pow(e, -x) * (x * x)) / 2;
}

function fb(x) {
  return 0.1 - (1 + x + (x * x) / 2) * pow(e, -x);
}

function dfb(x) {
  return (pow(e, -x) * (x * x)) / 2;
}

function rootFunction(start_value, f, df, func) {
  let x = 0,
    xn = start_value;

  let limit = pow(10, -6);
  let error;

  let cont = 0;
  while (1) {
    cont++;
    if (cont >= MAX) break;
    x = xn;
    xn = x - f(x) / df(x);

    error = abs(xn - x) / abs(xn);
    if (error < limit) break;
  }

  console.log(`Raiz da função ${func} -> F(${xn}) = ${round(f(xn))}`);
}

var readline = require("readline");

var input = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const q1 = () => {
  return new Promise((res, rej) => {
    input.question(`Chute inicial para a função ${fa_str}: `, (answer) => {
      rootFunction(parseFloat(answer), fa, dfa, fa_str);
      res();
    });
  });
};

const q2 = () => {
  return new Promise((res, rej) => {
    input.question(`Chute inicial para a função ${fb_str}: `, (answer) => {
      rootFunction(parseFloat(answer), fb, dfb, fb_str);
      res();
    });
  });
};

const main = async () => {
  await q1();
  await q2();
  input.close();
};

main();