#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <list>
using namespace std;

class PosNode {
public:
    int value;
    int new_value;
    int pass_thresh;
    int use_thresh;
    unordered_map<int,char> position = {{1,'.'},{2,'.'},{3,'.'},{4,'.'},{5,'.'},{6,'.'},{7,'.'},{8,'.'},{9,'.'}};
    list<unordered_map<int,char>> path;
    list<unordered_map<int,char>> best_path;
    //CONSTRUCTOR 1
    PosNode(){
        PosNode('.','.','.','.','.','.','.','.','.');
        this->best_path.push_back(position);
        this->path.push_back(position);
    }
    //CONSTRUCTOR 2
    PosNode(char no1, char no2, char no3, char no4, char no5, char no6, char no7, char no8, char no9) {
        this->position.at(1) = no1;
        this->position.at(2) = no2;
        this->position.at(3) = no3;
        this->position.at(4) = no4;
        this->position.at(5) = no5;
        this->position.at(6) = no6;
        this->position.at(7) = no7;
        this->position.at(8) = no8;
        this->position.at(9) = no9;
        this->best_path.push_back(position);
        this->path.push_back(position);
    }
    //CONSTRUCTOR 3
    PosNode(unordered_map<int,char> current_position){
        this->position = current_position;
        this->best_path.push_back(position);
        this->path.push_back(position);
    }

    void AssignPosition( int use_thresh, int pass_thresh){
        this->use_thresh = use_thresh;
        this->pass_thresh = pass_thresh;
    }

};

char val(unordered_map<int,char> pos, int index){ //DONE
    std::unordered_map<int, char>::const_iterator got = pos.find (index);
    if ( got == pos.end() )
        return ' ';
    else
        return got->second;
}

bool Xwin(unordered_map<int,char> pos) {
    if ((val(pos,1) == 'X' && val(pos,2) == 'X' && val(pos,3) == 'X')
        || (val(pos,4) == 'X' && val(pos,5) == 'X' && val(pos,6) == 'X')
        || (val(pos,7) == 'X' && val(pos,8) == 'X' && val(pos,9) == 'X')
        || (val(pos,1) == 'X' && val(pos,4) == 'X' && val(pos,7) == 'X')
        || (val(pos,2) == 'X' && val(pos,5) == 'X' && val(pos,8) == 'X')
        || (val(pos,3) == 'X' && val(pos,6) == 'X' && val(pos,9) == 'X')
        || (val(pos,1) == 'X' && val(pos,5) == 'X' && val(pos,9) == 'X')
        || (val(pos,3) == 'X' && val(pos,5) == 'X' && val(pos,7) == 'X'))
        return 1;
    return 0;
}

int XwinPos(unordered_map<int,char> pos) {
    int x_pos = 0;
    if (val(pos,1) != 'O' && val(pos,2) != 'O' && val(pos,3) != 'O') x_pos++;
    if (val(pos,4) != 'O' && val(pos,5) != 'O' && val(pos,6) != 'O') x_pos++;
    if (val(pos,7) != 'O' && val(pos,8) != 'O' && val(pos,9) != 'O') x_pos++;
    if (val(pos,1) != 'O' && val(pos,4) != 'O' && val(pos,7) != 'O') x_pos++;
    if (val(pos,2) != 'O' && val(pos,5) != 'O' && val(pos,8) != 'O') x_pos++;
    if (val(pos,3) != 'O' && val(pos,6) != 'O' && val(pos,9) != 'O') x_pos++;
    if (val(pos,1) != 'O' && val(pos,5) != 'O' && val(pos,9) != 'O') x_pos++;
    if (val(pos,3) != 'O' && val(pos,5) != 'O' && val(pos,7) != 'O') x_pos++;
    return x_pos;
}

bool Owin(unordered_map<int,char> pos) {
    if ((val(pos,1) == 'O' && val(pos,2) == 'O' && val(pos,3) == 'O')
        || (val(pos,4) == 'O' && val(pos,5) == 'O' && val(pos,6) == 'O')
        || (val(pos,7) == 'O' && val(pos,8) == 'O' && val(pos,9) == 'O')
        || (val(pos,1) == 'O' && val(pos,4) == 'O' && val(pos,7) == 'O')
        || (val(pos,2) == 'O' && val(pos,5) == 'O' && val(pos,8) == 'O')
        || (val(pos,3) == 'O' && val(pos,6) == 'O' && val(pos,9) == 'O')
        || (val(pos,1) == 'O' && val(pos,5) == 'O' && val(pos,9) == 'O')
        || (val(pos,3) == 'O' && val(pos,5) == 'O' && val(pos,7) == 'O'))
        return 1;
    return 0;
}

int OwinPos(unordered_map<int,char> pos) {
    int o_pos = 0;
    if (val(pos,1) != 'X' && val(pos,2) != 'X' && val(pos,3) != 'X') o_pos++;
    if (val(pos,4) != 'X' && val(pos,5) != 'X' && val(pos,6) != 'X') o_pos++;
    if (val(pos,7) != 'X' && val(pos,8) != 'X' && val(pos,9) != 'X') o_pos++;
    if (val(pos,1) != 'X' && val(pos,4) != 'X' && val(pos,7) != 'X') o_pos++;
    if (val(pos,2) != 'X' && val(pos,5) != 'X' && val(pos,8) != 'X') o_pos++;
    if (val(pos,3) != 'X' && val(pos,6) != 'X' && val(pos,9) != 'X') o_pos++;
    if (val(pos,1) != 'X' && val(pos,5) != 'X' && val(pos,9) != 'X') o_pos++;
    if (val(pos,3) != 'X' && val(pos,5) != 'X' && val(pos,7) != 'X') o_pos++;
    return o_pos;
}

// return M(n) - O(n)
int Efunc1(unordered_map<int,char> pos, char XorOturn){
    int evaluation_value;
    if (XorOturn == 'X'){
        evaluation_value = XwinPos(pos) - OwinPos(pos);
        if (Xwin(pos)) evaluation_value = INT_MAX;
        if (Owin(pos)) evaluation_value = INT_MIN;
    }
    if (XorOturn == 'O'){
        evaluation_value = OwinPos(pos) - XwinPos(pos);
        if (Owin(pos)) evaluation_value = INT_MAX;
        if (Xwin(pos)) evaluation_value = INT_MIN;
    }
    return evaluation_value;
}

//-M(n) + O(n)
int Efunc2(unordered_map<int,char> pos, char XorOturn){
    int evaluation_value;
    if (XorOturn == 'X'){
        evaluation_value = -1*XwinPos(pos) +1*OwinPos(pos);
        if (Xwin(pos)) evaluation_value = INT_MAX;
        if (Owin(pos)) evaluation_value = INT_MIN;
    }
    if (XorOturn == 'O'){
        evaluation_value = -1*OwinPos(pos) +1* XwinPos(pos);
        if (Owin(pos)) evaluation_value = INT_MAX;
        if (Xwin(pos)) evaluation_value = INT_MIN;
    }
    return evaluation_value;
}

//2*M(n) - O(n)
int Efunc3(unordered_map<int,char> pos, char XorOturn){
    int evaluation_value;
    if (XorOturn == 'X'){
        evaluation_value = 2*XwinPos(pos) - OwinPos(pos);
        if (Xwin(pos)) evaluation_value = INT_MAX;
        if (Owin(pos)) evaluation_value = INT_MIN;
    }
    if (XorOturn == 'O'){
        evaluation_value = 2*OwinPos(pos) - XwinPos(pos);
        if (Owin(pos)) evaluation_value = INT_MAX;
        if (Xwin(pos)) evaluation_value = INT_MIN;
    }
    return evaluation_value;
}

//8- O(n)
int Efunc4(unordered_map<int,char> pos, char XorOturn){
    int evaluation_value;
    if (XorOturn == 'X'){
        evaluation_value = 8 - 1*OwinPos(pos);
        if (Xwin(pos)) evaluation_value = INT_MAX;
        if (Owin(pos)) evaluation_value = INT_MIN;
    }
    if (XorOturn == 'O'){
        evaluation_value = 8 - 1*XwinPos(pos);
        if (Owin(pos)) evaluation_value = INT_MAX;
        if (Xwin(pos)) evaluation_value = INT_MIN;
    }
    return evaluation_value;
}

int Static(unordered_map<int,char> pos, char XorOturn, int func_id) {
    int e_value;
    switch(func_id){
        case 1: e_value = Efunc1(pos,XorOturn);
            break;
        case 2: e_value = Efunc2(pos,XorOturn);
            break;
        case 3: e_value = Efunc3(pos,XorOturn);
            break;
        case 4: e_value = Efunc4(pos,XorOturn);
            break;
    }
    return e_value;
}

bool DeepEnough(unordered_map<int,char> pos, int depth){
    int default_depth = 3 ;
    if (depth == default_depth || Xwin(pos) || Owin(pos))
        return 1;
    return 0;
}

list<PosNode> MoveGen(unordered_map<int,char> pos, char player_char){
    list<PosNode> successors;
    for (int i = 1; i <= 9; i++){
        if (val(pos,i) == '.') {
            PosNode succ;
            for (int j = 1; j <= 9; j++) succ.position.at(j) = val(pos,j);
            succ.position.at(i) = player_char;
            successors.push_back(succ);
        }
    }
    return successors;
}

void board(unordered_map<int,char> pos)
{
    cout << "     |     |     " << endl;
    cout << "  " << val(pos,1) << "  |  " << val(pos,2) << "  |  " << val(pos,3) << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << val(pos,4) << "  |  " << val(pos,5) << "  |  " << val(pos,6) << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << val(pos,7) << "  |  " << val(pos,8) << "  |  " << val(pos,9) << endl;
    cout << "     |     |     " << endl << endl;
}

char OppositeChar(char player_char){
    if ( player_char == 'X') return 'O';
    return 'X';
}

// use_thresh: maximum value static can compute
// pass_thresh:minimun value static can compute

PosNode* MinMaxAB(PosNode* cur, int depth, char player_char, int use_thresh, int pass_thresh, int func_id, char XorOturn)
{ cur->AssignPosition(use_thresh,pass_thresh);
    list<PosNode> successors;
    if (DeepEnough(cur->position, depth))
    {
        cur->value = Static(cur->position,XorOturn, func_id);
        cur->path = cur->path;
        return cur;
    } else
    {
        successors = MoveGen(cur->position, player_char);
    }
    if (successors.empty()) { // When the board is full
        cur->value = Static(cur->position, XorOturn, func_id);
        cur->path = cur->path;
        return cur;
    } else
    { list<PosNode>::iterator it;
        PosNode suc;
        for (it = successors.begin(); it != successors.end(); ++it) {
            suc = *it;
            PosNode* succ= &suc;
            PosNode *result_succ = MinMaxAB(succ, depth+1, OppositeChar(player_char), -1*pass_thresh, -1*use_thresh, func_id, XorOturn);
            cur->new_value = -1*result_succ->value;
            if (cur->new_value > cur->pass_thresh) {
                cur->pass_thresh = cur->new_value;
                cur->best_path = result_succ->path;
                (cur->best_path).push_front(succ->position);
            }
            if (cur->pass_thresh >= cur->use_thresh){
                cur->value = cur->pass_thresh;
                cur->path = cur->best_path;
                return cur;
            }
        }
    }
    cur->value = cur->pass_thresh;
    cur->path = cur-> best_path;
    return cur;
}

void AIgame(int func1, int func2){
    PosNode *initial_state = new PosNode();
    int i = 0;
    while(!Xwin(initial_state->path.front()) && !Owin(initial_state->path.front()) && i < 9) {
        if (i%2 == 0) initial_state = MinMaxAB(initial_state,0,'X',INT_MAX,INT_MIN,func1,'X');
        if (i%2 == 1) initial_state = MinMaxAB(initial_state,0,'O',INT_MAX,INT_MIN,func2,'O');
        cout << "Turn " << i + 1 << endl;
        board(initial_state->path.front());
        initial_state = new PosNode(initial_state->path.front());
        i++;
    }
    delete initial_state;
}

int main() {
    cout << "GAME 1: (1,2)" << endl;
    AIgame(1,2);
    cout << "___________________________________________________________________________"<< endl;

    cout << "GAME 2: (1,3)" << endl;
    AIgame(1,3);
    cout << "___________________________________________________________________________"<< endl;

    cout << "GAME 3: (1,4)" << endl;
    AIgame(1,4);
    cout << "___________________________________________________________________________"<< endl;

    cout << "GAME 4: (2,3)" << endl;
    AIgame(2,3);
    cout << "___________________________________________________________________________"<< endl;

    cout << "GAME 5: (3,4)" << endl;
    AIgame(2,4);
    cout << "___________________________________________________________________________"<< endl;

    cout << "GAME 6: (3,4)" << endl;
    AIgame(3,4);
    cout << "___________________________________________________________________________"<< endl;

}

