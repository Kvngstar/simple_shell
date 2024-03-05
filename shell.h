#ifndef shell_header
#define shell_header
#define max_Pathlength 100
char *GetLineInput(void);
void Tokenizer(char *, char **, char ***, int *);
int CalStrLen(char *);
int SemiColon(char *);
int Comment(char *);
int SeparateInstruction(char *, char **, char ***, int *, char ***, int);
int Executer(char *, char **, int, char ***);
int ExecuterSlachCommand(char *, char **, int, char ***);
int countAnd(char *);
void And(char *, char ***);
int SearchFuncName2(char *);
int SearchFuncName(char *, char **);
char *TrimInput(char *text);
char *JoinText(char **, int);
int countOr(char *text);
void Or(char *, char ***);

int SearchName(char *);
int SearchName2(char *);
void free_string_array(char **, int);
int print_env(void);
int clear(void);
int pwd(void);
int set_env(char *);
int get_env(char *);
int unset_env(char *);
int cd(char *);
int _strlen(char *);
/**
 * struct built_in_2 - Structure for built-in functions
 * @funcName: The name of the function
 * @function_pointer2: Pointer to the function
 */
struct built_in_2
{
	char *funcName;
	int (*function_pointer2)(void);
};
/**
* struct built_in - short description
* @funcName: first member
* @function_pointer: second member
*
* For handling functions
*/

struct built_in
{
	char *funcName;
	int (*function_pointer)(char *);
};
#endif
