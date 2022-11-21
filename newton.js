const MAX = 101;
const { abs, e, pow, round}= require('mathjs');

function fa(x) {
  return 0.9-(1+x+(x*x)/2)*pow(e, -x);
}

function dfa(x) {
  return pow(e, -x)*(x*x)/2;
}

function fb(x) {
    return 0.1-(1+x+(x*x)/2)*pow(e, -x);
}

function dfb(x) {
    return pow(e, -x)*(x*x)/2;
}

function rootFunction(start_value, f, df, func) {
  let x = 0, xn= start_value;

  let limit = pow(10, -6);
  let error;

  let cont=0;
  while (1) {
      cont++;
      if (cont >= MAX) break;
      x = xn;
      xn = x - (f(x) / df(x));

      error = abs(xn-x) / abs(xn);
      if(error < limit) break;
  }

  console.log(`Raiz da função ${func} -> F(${xn}) = ${round(f(xn))}`);
}

rootFunction(1, fa, dfa, "0.9-(1+x+x²/2)*e^(-x)");
rootFunction(5.1, fb, dfb, "0.1-(1+x+x²/2)*e^(-x)");