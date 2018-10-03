#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    char *wrd ;
    int c ;
    struct node *next ;
}sn;
struct hash{
    struct node *head , *tail ;
};

void insert( struct hash h[] , char str[] , int p , int s )
{
    char *word = (char*)malloc(sizeof(char)*s+1);
    strcpy( word , str);
    sn* temp = ( sn*)malloc( sizeof( sn));
    temp->wrd = word ;
    temp->next = NULL ;

if ( h[p].head == NULL ){
    temp->c = 1 ;
    h[p].head = temp ;
    h[p].tail = temp ;
    }
    else 
    {
    sn* ptr = h[p].head ;
    int f = 0 ;
    while( ptr != NULL ){
        if ( strcmp( temp->wrd , ptr->wrd ) == 0 ){
          ptr->c ++ ;
          f = 1 ;
          break ; 
        }
        ptr = ptr->next ;
        }
        if ( f == 0 ){
            temp->c = 1 ;
            h[p].tail->next = temp ;
            h[p].tail = temp ;
        }
    }
}
void search( char *srh , struct hash *h )
{
     int index = 0 , l = 0 , f = 0 ;
    while( srh[l] != '\0' )
    {
        index += srh[l++] ;
    }
    index /= 50 ;
    while( index > 50 )
    {
        index /= 50 ;
    }
    struct node *p1 = h[index].head ;
    while( p1 != NULL )
    {
        if ( strcmp( p1->wrd , srh ) == 0 )
        {
            printf("'%s' is found at index : %d\n",srh,index);
            f = 1 ;
            break ;
        }
        p1 = p1->next ;
    }
    if ( f == 0 )
    printf("word not found \n");
}
void display( char str[100] , struct hash *h )
{
    printf("\nINDEX    WORD AND OCCURRANCE\n\n");
     for ( int i = 0 ; i < 50 ; i++ )
    {
    struct node *ptr = h[i].head ;
    while( ptr != NULL )
    {
        if ( ptr == h[i].head )
        printf("%d    ",i) ;
        if ( ptr->next != NULL && strcmp (ptr->wrd , " ") != 0 )
        printf("%s(%d) -> ",ptr->wrd,ptr->c);
        else 
        printf("%s(%d)\n",ptr->wrd,ptr->c);
        ptr = ptr->next ;
        }
    }
}
int main(){
    char str[1000] , str1[20];
    struct hash h[100]={0} ;
    //printf("%d",h[0].c);
    //scanf(" %[^\n]s",str);
    scanf("%[^\n]s",str);
    int i = 0 , s = 0 , j = 0 , p ;
    //printf("%s\n",str);
    while( str[i] != '\0' )
    {
        if ( str[i] != ' ' )
        {
            str1[j++] = str[i] ;
            s++ ;
        }
         if ( str[i] == ' ' || str[i+1] == '\0' )
         {
            str1[j] = '\0' ;
            int s_a = 0 , k = 0 ;
            while( str1[k] != '\0')
            {
                s_a += str1[k++] ;
            }

            int pos = s_a / 50 ; 
            while ( pos > 50 )
            {
                pos /= 50 ;
            } 
            insert( h , str1 , pos , s );
            //printf("%s\n",str1);
            j = 0 ;
            s = 0 ;
        }
        i++ ;
    }
    display( str , h );
    char srh[20] ;
    printf("enter words to search\n");
    scanf("%s",srh);
    search( srh , h );
    return 0 ;
}