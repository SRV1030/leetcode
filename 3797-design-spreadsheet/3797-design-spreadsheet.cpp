class Spreadsheet {
public:
    vector<vector<int>>sheet;
    Spreadsheet(int rows) {
        sheet.resize(26,vector<int>(rows+1));
    }
    
    void setCell(string cell, int value) {
        int row=cell[0]-'A',cloumn=stoi(cell.substr(1));
        sheet[row][cloumn]=value;
    }
    
    void resetCell(string cell) {
        int row=cell[0]-'A',cloumn=stoi(cell.substr(1));
        sheet[row][cloumn]=0;
    }
    int getCellValue(string cell) {
        int row=cell[0]-'A',cloumn=stoi(cell.substr(1));
        return sheet[row][cloumn];
    }
    int getValue(string formula) {
        string op1,op2;
        int v1,v2;
        int i=1;
        for(;i<formula.size();i++){
            if(formula[i]=='+') {
                i++;
                break;
            } 
            op1+=formula[i];
        }
        for(;i<formula.size();i++)op2+=formula[i];
        v1 = isalpha(op1[0])?getCellValue(op1):stoi(op1);
        v2 = isalpha(op2[0])?getCellValue(op2):stoi(op2);
        return v1+v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */