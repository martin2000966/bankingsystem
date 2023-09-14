#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "STD_TYPES.H"
#include "accounts.h"


Account head;
u32 numOfAccs=0;


void setFirstTime(Account *myAcc){

    static u32 currentID=1;                           //to give it the bank id

        printf("\nplease enter the full name :\n");
        fflush(stdin);
        fgets((myAcc->fullName),50,stdin);

        printf("\nplease enter the adress:\n");
        fflush(stdin);
        fgets((myAcc->adress),50,stdin);

        printf("\nplease enter the national id:\n");
        scanf("%lu",&myAcc->nationalID);

        printf("\nplease enter the age:\n");
        scanf("%d",&myAcc->age);

        myAcc->bankID =currentID;
        printf("this account's ID is : %hu",myAcc->bankID);
        currentID++;                                    //updating the new value of id

        if(myAcc->age <21){
            myAcc->guardFlag=1;
            printf("\nplease enter the guard national id:\n");
            scanf("%lu",&myAcc->guardNationalID);


        }else {
            myAcc->guardFlag=0;
            myAcc->guardNationalID = NULL;
        }

        myAcc->accountStatus = 1;   //setting the defaul value (active)
        myAcc->balance = 0;


        //generating random password:
        for (u8 i =0 ;i <8 ; i++){
            (myAcc->password)[i]= (char)((rand()%61)+62);    //el 61 3ashan yeb2a odamo 61 options bas men el ascii
                                                            // w el 62 3ashan yebda mn el char rakam 62 w yakhod mo3zam el horouf
        }
        printf("\nyour new generated passowrd is(please save it):\n");
        for (u8 i =0 ;i <8 ; i++){
            printf("%c",(myAcc->password)[i]);
        }
        printf("\n");
}




//creating and adding to the linked list
void createAccount(){
    printf("********* CREATING NEW ACCOUNT*********");
    if(numOfAccs == 0){
        setFirstTime(&head);
        head.next =NULL;
    }else{
        Account *last;
        //alocate new node
        Account *new =(Account *)malloc(sizeof(Account));
        setFirstTime(new);
        new->next =NULL;

        last=&head;
        //searching for last node
        while (last->next != NULL){
            last=last->next;
        }
        last->next= new ;

    }
    numOfAccs++;
    fflush(stdin);
}


// void printAccount(Account *myAcc){
//     printf("");
// }



Account *getAccountByID(u32 argID){

    if(numOfAccs !=0){
        Account *last = &head;

        for(int i =1 ;i++ ;i<=numOfAccs){
            if (last!=NULL && last->bankID == argID){
                return last;
            }
            if(last == NULL){
                return NULL;
            }
            last =last->next;
        }
        return NULL;
    }
}





void makeTransaction(u32 senderID ,u32 recieverID ,f64 amount){
    Account*senderAcct = getAccountByID(senderID );
    Account*reciverAcct = getAccountByID(recieverID );
    if ((senderAcct!=NULL)&& (reciverAcct!=NULL) && senderAcct->accountStatus == 1 && reciverAcct->accountStatus ==1){
       
        if (senderAcct->balance < amount){
            printf("\n insufficient balance\n");
            return;
        }
        if(amount<0){
            printf("\n invalid transaction amount, IT SHOULD BE A POSITIVE VALUE! \n");
        }else{
            senderAcct ->balance -=  amount;
            reciverAcct->balance +=   amount;
            printf("\n--->TRANSITCTION IS DONE.\n");
        }

    }else {
        printf ("\ninvalid account number,it may be not found or deactivated account\n ");return;
    }

}


void setAccStatus (Account *myAcc){
    do {

        printf("\nplease select the required status:  1:activate   2:restricted   3:closed :\n");
        scanf("%d",&myAcc->accountStatus);
        if ((myAcc->accountStatus) > 3 || myAcc->accountStatus<1 ){
            printf("\n Wrong input please try again!\n");
            }
    }while((myAcc->accountStatus) > 3 || (myAcc->accountStatus<1));
        



}

void getCash(Account *myAcc){
    u8 status = myAcc->accountStatus ;
    if(status == 1 ){
        printf("\nenter the amount needed:\n");
        f64 withdraw;
        scanf("%lf",&withdraw);
        if(withdraw <= myAcc->balance){
            myAcc->balance -= withdraw;
            printf("\nthe remaining balance is : %f\n",myAcc->balance);
        }else{
            printf("\nsorry there isn't enough money in your account\n");
        }

    }else{
        printf("\nsorry the account isn't activated \n");
    }

}


void deposit (Account *myAcc){
    u8 status = (myAcc->accountStatus);      //error
    if(status == 1 ){
        printf("\nenter the amount to deposit:\n");
        f64 dep;
        scanf("%lf",&dep);

         myAcc->balance += dep;
         printf("\nthe new balance is : %f\n",myAcc->balance);



    }
    else{
        printf("\nsorry the account isn't activated \n");
    }

}










/***
 * *
 * men awel hena lel debug
 * 
 * **/

// Account *getBankIDAndPassword(){
//     u32 tempID ;
//     u8 tempPass [16];
//     printf("\nplease enter your bank ID :\n");
//     scanf("%d",&tempID);
//     Account *tempAcc= getAccountByID(tempID) ;
//     if (tempAcc == NULL){
//           printf("wrong id\n");
//         return NULL;
//     }
//     printf("\nplease enter your password:\n");
//     fflush(stdin);
//     fgets((tempPass),16,stdin);
//     fflush(stdin);
//     for(u16 i =0 ;i<16;i++){
//         if (tempPass[i] != *(tempAcc->password+i) && tempPass[i] != '\n'){
//             printf("\nwrong password\n");
//             return NULL;
//         }
//     }
//     return tempAcc;


// }

// int main (){

//     // openAdminWindow();
//     createAccount();
//     createAccount();
//     Account *acc1 = getBankIDAndPassword();
//     Account *acc2 = getAccountByID(2);
//     deposit(acc1);
//     printf("%f\n",acc1->balance);
//     printf("%d\n",acc1->bankID);
//     printf("%d\n",acc2->bankID);
//     makeTransaction(1,2,500);
//     printf("%f\n",acc1->balance);
//     printf("%f\n",acc2->balance);



// }













/******
 * ANOTHER TRIALS FOR DEBUGGUING ;)
*/
#include "window.h"



// void selectWindow(){
//     u8 choice=5;
//     printf("\n--------welcome to my bank system---------- \n");
    
    
//     while(choice !=0 ){
//         printf("please select the window needed :\n");
//         printf("(0)exit the program     (1)admin window     (2)client window:\n");
//         scanf("%hhu",&choice);
//         switch (choice)
//         {
//         case 1:
//             openAdminWindow();                   
//             break;
        
//         case 2:
//             openClientWindow();    
//             break;
//         case 0 :
//             break;
//         default:
//             printf("we get a wrong answer ...please re_enter the system\n");
//             break;
//         }
//     }
// }







// void openAdminWindow(){
//     u8 choice=0 ;
//     while(choice != 3 ){
//         printf("\n\n\n(((((((Welcome Admin Window))))))\n");
//         printf("\nchoose what you need to do :\n");
//         printf("    (1)create new account.\n");
//         printf("    (2)open an existing account.\n");
//         printf("    (3)exit the admin window(going back to the main sys).\n");
//         scanf ("%hhu",&choice );
    
//         switch (choice)
//         {
//         case 1:
//             createAccount();
//             printf("------->DONE CREATING A NEW ACCOUNT\n");
//             break;
        
//         case 2 :
//             u32 ID;
//             printf("\nenter the ID :\n");
//             scanf("%hd", &ID);
//             openAcc(ID);
//             break;

//         case 3 :
//             break;

//         default:
//             printf("we didn't get the right answer\n");
//             break;
//         }
//     }
// }






// void openAcc(u32 id){
//     Account *myAcc = getAccountByID(id);
//     if(myAcc!=NULL){
//     u8 choice = 0;
//         while (choice != 5 ){          //because 5 el mafroud yeraga3na lel admin window tani 8er kda ana hafdal fl account
            
//             printf("\n-----> this is %s 's account :\n",myAcc->fullName);
//             printf("pleas choose the operation to make:\n");
//             printf("    (1)make transaction\n");
//             printf("    (2)change account status\n");
//             printf("    (3)get cash\n");
//             printf("    (4)deposit money\n");
//             printf("    (5)return to the main ADMIN menu and exit the account\n");
//             scanf("%hhu",&choice);
            
//             switch (choice)
//             {
//             case 1:
//                 u32 rec ;
//                 f64 transactionMoney = 0;
//                 printf("enter the bankID of the reciever account :\n");
//                 scanf("%d",&rec);

//                 printf("\nplease enter the amount to be sent :\n");
//                 do {
//                     scanf("%lf",&transactionMoney);
//                     if(transactionMoney<0){
//                         printf("you can not send negative value, please try again!\n");
//                     }
//                 }while(transactionMoney<0);
//                 makeTransaction(id , rec , transactionMoney);
                
//                 break;

//             case 2 :
//                 setAccStatus(myAcc);
//                 printf("the status has been changed\n");
//                 break;

//             case 3 :
//                 getCash(myAcc);
//                 break;
            
//             case 4 :
//                 deposit(myAcc);
//                 break;
            
//             case 5:
//                 break;
            
            
//             default:
//                 printf("\nWRONG ANSWER\n");
//                 break;
//             }

//         }    

        
//     }
// }




// void openClientWindow(){
//     u8 choice=0 ;
//     printf("\n\n\n(((((((Welcome client Window))))))\n");
//     Account *myAcc = getBankIDAndPassword();
//     if (myAcc== NULL){
//         return;
//     }
//     printf("\nWELCOME ,to your account \n");
//     while(choice != 5 ){
//         printf("please choose the operation to make:\n");
//             printf("    (1)make transaction\n");
//             printf("    (2)change your password\n");
//             printf("    (3)get cash\n");
//             printf("    (4)deposit money\n");
//             printf("    (5)return to the main  menu and exit the account\n");
//             scanf("%hhu",&choice );


//             switch(choice ) {
                
//                 case  1:                //making transfare 
//                     printf("\n---->making transfer\n");
//                     u32 rec ;
//                     f64 transactionMoney = 0;
//                     printf("enter the bankID of the reciever account :\n");
//                     scanf("%d",&rec);

//                     printf("\nplease enter the amount to be sent :\n");
//                     do {
//                         scanf("%lf",&transactionMoney);
//                         if(transactionMoney<0){
//                             printf("you can not send negative value, please try again!\n");
//                         }
//                     }while(transactionMoney<0);
//                     makeTransaction(myAcc->bankID, rec , transactionMoney);
                    
//                 break;

//                 case 2 :                //change your password
//                     printf("\n---->now your setting a new password\n");
//                     u8 tempPassword[16]  ;
//                     u8 flag ;
//                     u8 resume =5;
                   
//                     do{
//                         flag =0;
//                         printf("\nplease enter you old password:\n");
//                         fflush(stdin);
//                         fgets((tempPassword),16,stdin);
//                         fflush(stdin);

//                         //if the entered password is similar to the old one
//                         for(u16 i =0 ;i<16;i++){
//                             if (tempPassword[i] != *(myAcc->password+i) && tempPassword[i] != '\n'){
//                                 printf("\nwrong password\n");
//                                 flag = 1 ;          //means that the password is wrong and u should try again 
//                                 break;
                                
//                             }
//                             if(tempPassword[i]=='\n'){break;}
//                         }
//                         if (flag == 1 ){
                            
//                             printf ("\nplease select your choice: (0)cancel changing my password  OR  (1)keep trying \n ");
//                             scanf("%hhu",&resume);
//                             if(resume==0){break;} 
//                         }
//                     }while(flag==1);
//                     if(resume==0){break;} 
//                     printf("\nplease enter the new password :\n");
//                     fflush(stdin);
//                     fgets(myAcc->password,16,stdin);
//                     fflush(stdin);
//                     printf("\nthe new password has been set successfully.\n\n\n");
//                 break;

//                 case 3 :
//                     getCash(myAcc);
//                 break;
            
//                 case 4 :
//                     deposit(myAcc);
//                 break; 

//                 case 5 : break;

//                 default: printf("\nwe recieved a wrong answer please try again\n");


                    

//             }


//     }
// }





// Account *getBankIDAndPassword(){
//     u32 tempID ;
//     u8 tempPass [16];
//     printf("\nplease enter your bank ID :\n");
//     scanf("%d",&tempID);
//     Account *tempAcc= getAccountByID(tempID) ;
//     if (tempAcc == NULL){
//           printf("wrong id\n");
//         return NULL;
//     }
//     printf("\nplease enter your password:\n");
//     fflush(stdin);
//     fgets((tempPass),16,stdin);
//     fflush(stdin);
//     for(u16 i =0 ;i<16;i++){
//         if (tempPass[i] != *(tempAcc->password+i) && tempPass[i] != '\n'){
//             printf("\nwrong password\n");
//             return NULL;
//         }
//         if(tempPass[i]== '\n' || *(tempAcc->password+i)==0){
//             break;
//         }
//     }
//     return tempAcc;


// }




// int main(){
//     selectWindow();
// }