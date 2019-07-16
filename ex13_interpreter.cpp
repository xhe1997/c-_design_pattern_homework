struct ExpressionProcessor {
  map<char,int> variables;

  enum NextOp {
    nothing,
    plus,
    minus
  };

  int calculate(const string& expression) {
    int current;
    auto next_op = nothing;

    auto parts = split(expression);

    cout << "parts (" << parts.size() << "): ";
    for (auto& part : parts)
      cout << "`" << part << "` ";
    cout << endl;

    for (auto& part : parts) {
      auto no_op = split(part);
      auto first = no_op[0];
      int value, z;

      try {
        value = stoi(first);
      }
      catch (const invalid_argument&) {
        if (first.length() == 1 &&
            variables.find(first[0]) != variables.end()) {
          value = variables[first[0]];
        }
        else return 0;
      }

      switch (next_op) {
        case nothing:
          current = value;
          break;
        case plus:
          current += value;
          break;
        case minus:
          current -= value;
          break;
      }

      if (*part.rbegin() == '+') next_op = plus;
      else if (*part.rbegin() == '-') next_op = minus;
    }
    return current;
  }
};
