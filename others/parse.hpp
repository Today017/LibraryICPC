#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <stdexcept>
#include <cctype>

class Node {
public:
    std::string value;
    std::vector<std::shared_ptr<Node>> children;

    Node(const std::string& val) : value(val) {}
};

enum TokenType { IDENTIFIER, NUMBER, OPERATOR, LPAREN, RPAREN, END };

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& input, char separator) : input(input), pos(0), separator(separator) {}

    Token getNextToken() {
        while (pos < input.length()) {
            if (isspace(input[pos]) || input[pos] == separator) {
                ++pos;
                continue;
            }
            if (isalpha(input[pos])) {
                return getId();
            }
            if (isdigit(input[pos])) {
                return getNumber();
            }
            if (ispunct(input[pos])) {
                if (input[pos] == '(') {
                    return createToken(LPAREN, "(");
                } else if (input[pos] == ')') {
                    return createToken(RPAREN, ")");
                } else {
                    return getOperator();
                }
            }
            throw std::runtime_error("Unknown character: " + std::string(1, input[pos]));
        }
        return Token{END, ""};
    }

private:
    std::string input;
    size_t pos;
    char separator;

    Token createToken(TokenType type, const std::string& value) {
        ++pos;
        return Token{type, value};
    }

    Token getId() {
        size_t start = pos;
        while (pos < input.length() && isalpha(input[pos])) {
            ++pos;
        }
        return Token{IDENTIFIER, input.substr(start, pos - start)};
    }

    Token getNumber() {
        size_t start = pos;
        while (pos < input.length() && isdigit(input[pos])) {
            ++pos;
        }
        return Token{NUMBER, input.substr(start, pos - start)};
    }

    Token getOperator() {
        size_t start = pos;
        while (pos < input.length() && ispunct(input[pos]) && input[pos] != '(' && input[pos] != ')' && input[pos] != separator) {
            ++pos;
        }
        return Token{OPERATOR, input.substr(start, pos - start)};
    }
};

struct OperatorInfo {
    int precedence;
};

class Grammar {
public:
    void addOperator(const std::string& op, int precedence) {
        operators[op] = {precedence};
    }

    const OperatorInfo& getOperatorInfo(const std::string& op) const {
        return operators.at(op);
    }

    bool isOperator(const std::string& token) const {
        return operators.find(token) != operators.end();
    }

private:
    std::unordered_map<std::string, OperatorInfo> operators;
};

enum Notation { INFIX, PREFIX, POSTFIX };

class Parser {
public:
    Parser(const std::string& input, const Grammar& grammar, Notation notation, char separator)
        : lexer(input, separator), grammar(grammar), currentToken(lexer.getNextToken()), notation(notation) {}

    std::shared_ptr<Node> parse() {
        if (notation == INFIX) {
            return parseInfix();
        } else if (notation == PREFIX) {
            return parsePrefix();
        } else if (notation == POSTFIX) {
            return parsePostfix();
        } else {
            throw std::runtime_error("Unknown notation");
        }
    }

private:
    Lexer lexer;
    Grammar grammar;
    Token currentToken;
    Notation notation;

    void eat(TokenType type) {
        if (currentToken.type == type) {
            currentToken = lexer.getNextToken();
        } else {
            throw std::runtime_error("Unexpected token: " + currentToken.value);
        }
    }

    std::shared_ptr<Node> parseInfix() {
        return expr(0);
    }

    std::shared_ptr<Node> expr(int precedence) {
        auto node = factor();
        while (currentToken.type == OPERATOR && grammar.getOperatorInfo(currentToken.value).precedence >= precedence) {
            auto op = currentToken;
            int opPrecedence = grammar.getOperatorInfo(op.value).precedence;
            eat(OPERATOR);
            auto right = expr(opPrecedence);
            if (node->value == op.value) {
                node->children.push_back(right);
            } else {
                auto newNode = std::make_shared<Node>(op.value);
                newNode->children.push_back(node);
                newNode->children.push_back(right);
                node = newNode;
            }
        }
        return node;
    }

    std::shared_ptr<Node> factor() {
        if (currentToken.type == NUMBER || currentToken.type == IDENTIFIER) {
            auto node = std::make_shared<Node>(currentToken.value);
            eat(currentToken.type);
            return node;
        } else if (currentToken.type == LPAREN) {
            eat(LPAREN);
            auto node = expr(0);
            eat(RPAREN);
            return node;
        } else {
            throw std::runtime_error("Unexpected token: " + currentToken.value);
        }
    }

    std::shared_ptr<Node> parsePrefix() {
        if (currentToken.type == END) {
            return nullptr;
        }
        if (currentToken.type == OPERATOR) {
            auto node = std::make_shared<Node>(currentToken.value);
            eat(OPERATOR);
            while (currentToken.type != END) {
                node->children.push_back(parsePrefix());
            }
            return node;
        } else if (currentToken.type == NUMBER || currentToken.type == IDENTIFIER) {
            auto node = std::make_shared<Node>(currentToken.value);
            eat(currentToken.type);
            return node;
        } else if (currentToken.type == LPAREN) {
            eat(LPAREN);
            auto node = parsePrefix();
            eat(RPAREN);
            return node;
        } else {
            throw std::runtime_error("Unexpected token: " + currentToken.value);
        }
    }

    std::shared_ptr<Node> parsePostfix() {
        std::vector<std::shared_ptr<Node>> stack;
        while (currentToken.type != END) {
            if (currentToken.type == NUMBER || currentToken.type == IDENTIFIER) {
                stack.push_back(std::make_shared<Node>(currentToken.value));
                eat(currentToken.type);
            } else if (currentToken.type == OPERATOR) {
                auto node = std::make_shared<Node>(currentToken.value);
                eat(OPERATOR);
                while (!stack.empty() && (currentToken.type == END || currentToken.type == RPAREN)) {
                    node->children.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(node);
            } else if (currentToken.type == LPAREN) {
                eat(LPAREN);
                stack.push_back(parsePostfix());
                eat(RPAREN);
            } else {
                throw std::runtime_error("Unexpected token: " + currentToken.value);
            }
        }
        if (stack.size() != 1) {
            throw std::runtime_error("Invalid postfix expression");
        }
        return stack.back();
    }
};

void printTree(const std::shared_ptr<Node>& node, int indent = 0) {
    if (!node) return;
    for (int i = 0; i < indent; ++i) std::cout << "  ";
    std::cout << node->value << std::endl;
    for (const auto& child : node->children) {
        printTree(child, indent + 1);
    }
}