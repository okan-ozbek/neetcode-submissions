public class Solution {
    public int EvalRPN(string[] tokens) {
        Stack<int> values = new();

        int first = 0;
        int second = 0;

        foreach(string token in tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                second = values.Pop();
                first = values.Pop();

                if (token == "+") {
                    values.Push(first + second);
                } 
                else if (token == "-") {
                    values.Push(first - second);
                }
                else if (token == "*") {
                    values.Push(first * second);
                } 
                else {
                    values.Push(first / second);
                }
            } else {
                values.Push(int.Parse(token));
            }
        }

        return values.Pop();
    }
}
