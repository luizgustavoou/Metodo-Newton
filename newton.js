const MAX = 101;
const { abs, e, pow, round}= require('mathjs');

function fa(x) {
  return 0.9-(1+x+(x*x)/2)*pow(e, -x);
}

function dfa(x) {
  return pow(e, -x)*(x*x)/2;
}

function rootFA() {
  let x = 0.0, xn= 1;

  let limit = pow(10, -6);
  let error;

  let cont=0;
  while (1) {
      cont++;
      if (cont >= MAX) break;
      x = xn;
      xn = x - (fa(x) / dfa(x));

      error = abs(xn-x) / abs(xn);
      if(error < limit) break;
  }

  console.log(`Raiz de fa ${xn} -> Fa(${xn}) = ${round(fa(xn))}`);
}

rootFA();