# SLP Gate learning
## Description
A Single-Layer Perceptron(SLP) learns basic logic gates using the perceptron learning rule.

## Gates
| Gate | Learnable by SLP | Note                   |
| ---- | :--------------: | ---------------------- |
| AND  | ✅ | in work |
| OR   | ✅ | works |
| NAND | ✅ | in work |
| NOR  | ✅ | in work |
| XOR  | ❌ | not linearly separable |
| XNOR | ❌ | not linearly separable |

## How it works
1. The perceptron computes a weighted sum of its inputs plus a bias:
```
    sum = w1 * x1 + w2 * x2 + b
    output = 1 if sum > 0, otherwise 0
```
2. During training, after each example the weights are updated only when
the output is wrong:
```
    error = target - output
    w1 = w1 + error * x1
    w2 = w2 + error * x2
    b  = b + error
```
3. Training stops when the perceptron classifies all four input combinations correctly.

## Why not XOR and XNOR?
A single perceptron can only separate outputs with one straight line. 
For XOR and XNOR, the 1s lie on one diagonal and the 0s on the other, so no single line can separate them. 
In order to solve these gates MLP (Multi-Layer Perceptron) is needed because its hidden layer allows it to combine several lines.

## Build & run
Open `SLP-gate-learning.sln` in Visual Studio and run the project (Ctrl+F5).

## License
MIT
