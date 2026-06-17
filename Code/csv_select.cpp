#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct CSVTable {
    vector<string> headers;
    vector<vector<string>> rows;
};

string trim(const string& text) {
    size_t start = text.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";

    size_t end = text.find_last_not_of(" \t\r\n");
    return text.substr(start, end - start + 1);
}

string toLower(string text) {
    transform(text.begin(), text.end(), text.begin(), [](unsigned char c) {
        return tolower(c);
    });
    return text;
}

string removeQuotes(string text) {
    text = trim(text);

    if (text.size() >= 2) {
        if ((text.front() == '\'' && text.back() == '\'') ||
            (text.front() == '"' && text.back() == '"')) {
            return text.substr(1, text.size() - 2);
        }
    }

    return text;
}

vector<string> splitCSVLine(const string& line) {
    vector<string> result;
    string cell;
    bool insideQuotes = false;

    for (char c : line) {
        if (c == '"') {
            insideQuotes = !insideQuotes;
        } else if (c == ',' && !insideQuotes) {
            result.push_back(trim(cell));
            cell.clear();
        } else {
            cell += c;
        }
    }

    result.push_back(trim(cell));
    return result;
}

vector<string> splitByComma(const string& text) {
    vector<string> result;
    string item;
    stringstream ss(text);

    while (getline(ss, item, ',')) {
        result.push_back(trim(item));
    }

    return result;
}

int getColumnIndex(const vector<string>& headers, const string& columnName) {
    for (int i = 0; i < static_cast<int>(headers.size()); i++) {
        if (toLower(headers[i]) == toLower(trim(columnName))) {
            return i;
        }
    }

    return -1;
}

bool isNumber(const string& text) {
    if (text.empty()) return false;

    char* endPtr = nullptr;
    strtod(text.c_str(), &endPtr);

    return *endPtr == '\0';
}

bool compareValues(const string& leftValue, const string& op, const string& rightValue) {
    string left = removeQuotes(leftValue);
    string right = removeQuotes(rightValue);

    if (isNumber(left) && isNumber(right)) {
        double a = stod(left);
        double b = stod(right);

        if (op == "=" || op == "==") return a == b;
        if (op == "!=") return a != b;
        if (op == ">") return a > b;
        if (op == "<") return a < b;
        if (op == ">=") return a >= b;
        if (op == "<=") return a <= b;
    } else {
        if (op == "=" || op == "==") return left == right;
        if (op == "!=") return left != right;
        if (op == ">") return left > right;
        if (op == "<") return left < right;
        if (op == ">=") return left >= right;
        if (op == "<=") return left <= right;
    }

    return false;
}

CSVTable loadCSV(const string& filename) {
    CSVTable table;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Cannot open CSV file: " << filename << endl;
        return table;
    }

    string line;

    if (getline(file, line)) {
        table.headers = splitCSVLine(line);
    }

    while (getline(file, line)) {
        if (!trim(line).empty()) {
            table.rows.push_back(splitCSVLine(line));
        }
    }

    return table;
}

void showColumns(const CSVTable& table) {
    cout << "Available columns:" << endl;

    for (const string& header : table.headers) {
        cout << "- " << header << endl;
    }

    cout << endl;
}

void printResultTable(const vector<string>& selectedHeaders, const vector<vector<string>>& resultRows) {
    if (selectedHeaders.empty()) {
        cout << "No selected columns." << endl;
        return;
    }

    vector<int> widths(selectedHeaders.size(), 0);

    for (int i = 0; i < static_cast<int>(selectedHeaders.size()); i++) {
        widths[i] = selectedHeaders[i].size();
    }

    for (const auto& row : resultRows) {
        for (int i = 0; i < static_cast<int>(row.size()); i++) {
            widths[i] = max(widths[i], static_cast<int>(row[i].size()));
        }
    }

    for (int i = 0; i < static_cast<int>(selectedHeaders.size()); i++) {
        cout << left << setw(widths[i] + 2) << selectedHeaders[i];
    }
    cout << endl;

    for (int width : widths) {
        cout << string(width, '-') << "  ";
    }
    cout << endl;

    for (const auto& row : resultRows) {
        for (int i = 0; i < static_cast<int>(row.size()); i++) {
            cout << left << setw(widths[i] + 2) << row[i];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Total rows: " << resultRows.size() << endl;
}

vector<string> parseCondition(const string& condition) {
    vector<string> operators = {">=", "<=", "!=", "==", "=", ">", "<"};

    for (const string& op : operators) {
        size_t pos = condition.find(op);

        if (pos != string::npos) {
            string column = trim(condition.substr(0, pos));
            string value = trim(condition.substr(pos + op.size()));
            return {column, op, value};
        }
    }

    return {};
}

void executeSelect(const CSVTable& table, string query) {
    query = trim(query);

    if (!query.empty() && query.back() == ';') {
        query.pop_back();
    }

    string lowerQuery = toLower(query);

    size_t selectPos = lowerQuery.find("select ");
    size_t fromPos = lowerQuery.find(" from ");

    if (selectPos != 0 || fromPos == string::npos) {
        cout << "Invalid query format." << endl;
        cout << "Example: SELECT name, score FROM students WHERE score >= 80;" << endl;
        return;
    }

    string columnPart = trim(query.substr(7, fromPos - 7));

    size_t wherePos = lowerQuery.find(" where ");
    size_t orderPos = lowerQuery.find(" order by ");

    size_t tableNameEnd = query.size();

    if (wherePos != string::npos) {
        tableNameEnd = wherePos;
    }

    if (orderPos != string::npos) {
        tableNameEnd = min(tableNameEnd, orderPos);
    }

    string tableName = trim(query.substr(fromPos + 6, tableNameEnd - (fromPos + 6)));

    if (toLower(tableName) != "students") {
        cout << "Note: This program uses the uploaded CSV as one table. Suggested table name: students" << endl;
    }

    vector<int> selectedIndexes;
    vector<string> selectedHeaders;

    if (columnPart == "*") {
        for (int i = 0; i < static_cast<int>(table.headers.size()); i++) {
            selectedIndexes.push_back(i);
            selectedHeaders.push_back(table.headers[i]);
        }
    } else {
        vector<string> columns = splitByComma(columnPart);

        for (const string& column : columns) {
            int index = getColumnIndex(table.headers, column);

            if (index == -1) {
                cout << "Error: Column not found: " << column << endl;
                showColumns(table);
                return;
            }

            selectedIndexes.push_back(index);
            selectedHeaders.push_back(table.headers[index]);
        }
    }

    vector<vector<string>> filteredRows = table.rows;

    if (wherePos != string::npos) {
        size_t conditionStart = wherePos + 7;
        size_t conditionEnd = (orderPos != string::npos) ? orderPos : query.size();

        string condition = trim(query.substr(conditionStart, conditionEnd - conditionStart));
        vector<string> conditionParts = parseCondition(condition);

        if (conditionParts.size() != 3) {
            cout << "Invalid WHERE condition." << endl;
            cout << "Example: WHERE department = 'CS'" << endl;
            cout << "Example: WHERE score >= 80" << endl;
            return;
        }

        string whereColumn = conditionParts[0];
        string op = conditionParts[1];
        string whereValue = conditionParts[2];

        int whereIndex = getColumnIndex(table.headers, whereColumn);

        if (whereIndex == -1) {
            cout << "Error: WHERE column not found: " << whereColumn << endl;
            showColumns(table);
            return;
        }

        vector<vector<string>> tempRows;

        for (const auto& row : filteredRows) {
            if (whereIndex < static_cast<int>(row.size()) &&
                compareValues(row[whereIndex], op, whereValue)) {
                tempRows.push_back(row);
            }
        }

        filteredRows = tempRows;
    }

    if (orderPos != string::npos) {
        string orderPart = trim(query.substr(orderPos + 10));
        stringstream ss(orderPart);

        string orderColumn;
        string direction = "ASC";

        ss >> orderColumn;
        ss >> direction;

        int orderIndex = getColumnIndex(table.headers, orderColumn);

        if (orderIndex == -1) {
            cout << "Error: ORDER BY column not found: " << orderColumn << endl;
            showColumns(table);
            return;
        }

        bool descending = (toLower(direction) == "desc");

        sort(filteredRows.begin(), filteredRows.end(),
             [&](const vector<string>& a, const vector<string>& b) {
                 string left = (orderIndex < static_cast<int>(a.size())) ? a[orderIndex] : "";
                 string right = (orderIndex < static_cast<int>(b.size())) ? b[orderIndex] : "";

                 if (isNumber(left) && isNumber(right)) {
                     double x = stod(left);
                     double y = stod(right);
                     return descending ? x > y : x < y;
                 }

                 return descending ? left > right : left < right;
             });
    }

    vector<vector<string>> resultRows;

    for (const auto& row : filteredRows) {
        vector<string> selectedRow;

        for (int index : selectedIndexes) {
            if (index < static_cast<int>(row.size())) {
                selectedRow.push_back(row[index]);
            } else {
                selectedRow.push_back("");
            }
        }

        resultRows.push_back(selectedRow);
    }

    printResultTable(selectedHeaders, resultRows);
}

int main(int argc, char* argv[]) {
    string filename = "students(1)(1).csv";

    if (argc >= 2) {
        filename = argv[1];
    }

    CSVTable table = loadCSV(filename);

    if (table.headers.empty()) {
        return 1;
    }

    cout << "CSV Mini Database - SELECT Feature" << endl;
    cout << "Loaded CSV file: " << filename << endl;
    cout << "Rows loaded: " << table.rows.size() << endl;
    cout << endl;

    showColumns(table);

    cout << "Supported query examples:" << endl;
    cout << "SELECT * FROM students;" << endl;
    cout << "SELECT name, score FROM students;" << endl;
    cout << "SELECT * FROM students WHERE department = 'CS';" << endl;
    cout << "SELECT name, department, score FROM students WHERE score >= 80 ORDER BY score DESC;" << endl;
    cout << endl;

    cout << "Enter a SELECT query:" << endl;
    cout << "> ";

    string query;
    getline(cin, query);

    executeSelect(table, query);

    return 0;
}
