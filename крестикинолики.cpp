
#include <iostream>
char board[16] = {};

void clearscreen(){// очищает окно консоли, функция clearscreen ни чего не возвращае.
     for(int i = 0; i<100; i++){
            std::cout<<std::endl;
  }
}

void clearboard(){//эта функция очищает доску и ни чего не возвращает
    for(int i = 0; i<17; i++){
            board[i] = '-';
    }

}

bool has_wonQ(char player){
  int wins[10][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15}, {0,4,8,12},{1,5,9,13},
                     {2,6,10,14}, {3,7,11,15}, {0,5,10,15}, {3,6,9,12}};

       for(int i = 0; i<10; i++){
           int count = 0;
           for(int j = 0; j<4; j++){
               if(board[wins[i][j]] == player)
               count++;
    }
    if(count == 4){
       return true;
    }
  }
  return false;
}

void print_board(std::string indent){
  std::cout << std::endl;
  std::cout<<indent<<"-"<<board[12]<<"-|-"<<board[13]<<"-|-"<<board[14]<<"-|-"<<board[16]<<"- \n";
  std::cout<<indent<<"-"<<board[8]<<"-|-"<<board[9]<<"-|-"<<board[10]<<"-|-"<<board[11]<<"- \n";
  std::cout<<indent<<"-"<<board[4]<<"-|-"<<board[5]<<"-|-"<<board[6]<<"-|-"<<board[7]<<"- \n";
  std::cout<<indent<<"-"<<board[0]<<"-|-"<<board[1]<<"-|-"<<board[2]<<"-|-"<<board[3]<<"- \n";
}
int get_move(){
     std::cout<<"\nMenu hodov: \n";
  std::cout<<"13-|-14|-15|-16" << std::endl;
  std::cout<<"-9-|-10|-11|-12" << std::endl;
  std::cout<<"-5-|-6-|-7-|-8-" << std::endl;
  std::cout<<"-1-|-2-|-3-|-4-" << std::endl;
  std::cout<<"\n";

print_board("");
std::cout << "\nVvod chisla: ";


  int move;
  std::cin >> move;
  while(move > 16 || move < 1 || board[move-1]!= '-'){ //|| move >= 'A' && move <= 'Z' || move >= 'a' && move <= 'z'
  std::cout<<"Vvedite chislo ot (1 do 16):\n";
  std::cin >> move;
  }
  return move;
}

char play_and_get_winner(){
    int turn = 1;

    while(!has_wonQ('X') && !has_wonQ('0')){
           clearscreen();
           int move = get_move();
           clearscreen();
           if(turn%2 == 1){
              board[move-1]='X';
               if(has_wonQ('X')){
               std::cout <<"X,Pozdravlyau vi vuigrali!\n";
               return 'X';
               }

      }
       else{
              board[move-1]='0';
              if(has_wonQ('0')){
              std::cout <<"Y,Pozdravlyau vi vuigrali!\n";
              return '0';
        }
      }
    turn++;
    if(turn == 17){
    std::cout << "nechya\n";
    return 'D';
    }
  }
}

int main(){
    std::cout <<"Privetstvuyu\n\n";
    std::string reply = "y";
    int x_wins=0, o_wins=0, ties=0;

    while(reply == "y"){
    clearboard();
    char winner = play_and_get_winner();
    print_board("\t  ");

    switch(winner){
      case 'X':
        x_wins++;
        break;
     case '0':
        o_wins++;
        break;
     case 'D':
        ties++;
        break;
    }

    std::cout << "\n\t*Winer statistic*\nPlayer X: " << x_wins
              << ", Player 0: "<<o_wins << " and Ties: "<<ties<<"\n\n";
    std::cout << "\n would you like to play again? (y/n): ";
    std::cin  >> reply;
        while(reply != "y" && reply !="n"){
    std::cout << "please inter a valid reply (y/n):";
    std::cin  >> reply;
    }

   }// конец ваил лупа

  return 0;

}
