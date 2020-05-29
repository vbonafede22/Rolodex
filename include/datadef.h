#define ABORTSTRING "\\"
#define ABORTCHAR '\\'

#define MAXMATCHES 17

#define N_BASIC_FIELDS 8
#define OTHER -1

typedef enum {  //typedef enum Basic_Field{

    R_NAME = 0, R_WORK_PHONE, R_HOME_PHONE, R_COMPANY, R_WORK_ADDRESS,
    R_HOME_ADDRESS, R_REMARKS, R_UPDATED

  } Basic_Field;    
    
extern char *Field_Names[];  
  
/* A Rolodex entry */

typedef struct {

    char *basicfields[N_BASIC_FIELDS];
    int n_others;
    char **other_fields;

  } Rolo_Entry, *Ptr_Rolo_Entry;

  
#define get_basic_rolo_field(n,x) (((x) -> basicfields)[(n)])
#define get_n_others(x) ((x) -> n_others)  
#define get_other_field(n,x) (((x) -> other_fields)[n])
  
#define set_basic_rolo_field(n,x,s) (((x) -> basicfields[(n)]) = (s))
#define set_n_others(x,n) (((x) -> n_others) = (n))
#define incr_n_others(x) (((x) -> n_others)++)
#define set_other_field(n,x,s) ((((x) -> other_fields)[n]) = (s))

typedef struct link {

    Ptr_Rolo_Entry entry;
    int matched;
    struct link *prev;
    struct link *next;

  } Rolo_List, *Ptr_Rolo_List;


#define get_next_link(x) ((x) -> next)
#define get_prev_link(x) ((x) -> prev)
#define get_entry(x)     ((x) -> entry)
#define get_matched(x) ((x) -> matched)

#define set_next_link(x,y) (((x) -> next) = (y))
#define set_prev_link(x,y) (((x) -> prev) = (y))
#define set_entry(x,y) (((x) -> entry) = (y))
#define set_matched(x) (((x) -> matched) = 1)
#define unset_matched(x) (((x) -> matched) = 0);

extern Ptr_Rolo_List Begin_Rlist;
extern Ptr_Rolo_List End_Rlist;

#define MAXLINELEN 80
#define DIRPATHLEN 100

extern int changed;
extern int reorder_file;
extern int rololocked;

extern char *rolo_emalloc();
extern char *myMalloc();
extern Ptr_Rolo_List new_link_with_entry();
extern char *copystr();
extern int compare_links();
extern char *timestring();
extern char *homedir(), *libdir();
extern char *getenv();
extern char *ctime();
extern char *select_search_string();
extern int in_search_mode;


void write_rolo();    //i added this
void cathelpfile();    //i added this
int clearinit();      //i added this 
int clear_the_screen();   //i added this
void save_and_exit();  //i added this
int read_rolodex();   //i added this
int rlength();        //i added this
void rolo_reorder();  //i added this
void print_short();    //i added this 
void print_people();  //i added this
void interactive_rolo();  //i added this
int rolo_menu_yes_no();  //i added this
void any_char_to_continue();  //i added this
void user_eof();      //i added this
void display_entry(); //i added this
void rolo_insert();   //i added this
void rolo_peruse_mode();  //i added this
void rolo_update_mode();  //i added this
void rolo_delete();   //i added this
void roloexit();      //i added this 
void rolo_search_mode();    //i added this
void rolo_add();      //i added this
int select_field_to_search_by();    //i added this
void save_to_disk();    //i added this 
void display_entry_for_update();
int rolo_menu_data_help_or_abort();
void display_field_names();
int rolo_menu_number_help_or_abort();
int entry_action();
void display_list_of_entries();
void summarize_entry_list();
void look_for_person();