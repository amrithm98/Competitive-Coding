#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct file
{   
	char filename[100];
	struct file *link;
};

struct directory
{
	char dirname[100];
	struct directory *link;
	struct file *files;
};

void display_directory_names(struct directory **);
void append_directory(struct directory **);
void display_files(struct directory **);
struct directory *search_for_directory(struct directory **, char []);
void delete_file(struct directory **, char []);
void search_file(struct directory **, char []);
void delete_directory(struct directory **, char []);
void create_file(struct directory **, char []);

int main ()
{
	struct directory *p;
	int choice;
	struct directory *temp;
	p = NULL;
	char dname[100], fname[100];
	while (1)
	{
		printf("\n-------------------------------------------------------------\n");
		printf("Enter 1 to display all the directories in the ROOT directory\n");
		printf("Enter 2 to add a new directory\n");
		printf("Enter 3 to display all the files in a directory\n");
		printf("Enter 4 to search for a directory\n");
		printf("Enter 5 to delete a file in a directory\n");
		printf("Enter 6 to search for a file \n");
		printf("Enter 7 to delete a directory\n");
		printf("Enter 8 to create a new file\n");
		printf("Enter 9 to exit\n");
		printf("Make your choice\n");
		scanf("%d", &choice);
		printf("-------------------------------------------------------------\n\n");
		switch(choice)
		{
			case 1:
				display_directory_names(&p);
				break;
			case 2:
				append_directory(&p);
				break;
			case 3:
				printf("Enter the name of the directory\n");
				scanf("%s", dname);
				temp = search_for_directory(&p, dname);
				if (temp == NULL)
				{
					break;
				}
				display_files(&temp);
				break;
			case 4:
				printf("Enter the name of the directory to be searched for\n");
				scanf("%s", dname);
				temp = search_for_directory(&p, dname);
				if (temp == NULL)
				{
					break;
				}
				break;
			case 5:
				printf("Enter the name of the directory\n");
				scanf("%s", dname);
				temp = search_for_directory(&p, dname);
				if (temp == NULL)
				{
					break;
				}
				printf("Enter the name of the file to be deleted\n");
				scanf("%s", fname);
				delete_file(&temp, fname);
				break;
			case 6:
				printf("Enter the name of the directory\n");
				scanf("%s", dname);
				temp = search_for_directory(&p, dname);
				if (temp == NULL)
				{
					break;
				}
				printf("Enter the name of the file to be searched for\n");
				scanf("%s", fname);
				search_file(&temp, fname);
				break;
			case 7:
				printf("Enter the name of the directory to be deleted\n");
				scanf("%s", dname);
				delete_directory(&p, dname);
				break;
			case 8:
				printf("Enter the name of the directory where the new file is to be created\n");
				scanf("%s", dname);
				temp = search_for_directory(&p, dname);
				if (temp == NULL)
				{
					break;
				}
				printf("Enter the name of the file to be created\n");
				scanf("%s", fname);
				create_file(&temp, fname);
				break;
			case 9:
				exit(0);
			default:
				printf("Enter a valid choice\n");
				break;
		}
	}
	return 0;
}

void display_directory_names(struct directory **p)
{
	struct directory *temp;
	temp = (*p);
	if (temp == NULL)
	{
		printf("No directories inserted into the root directory\n");
		return;
	}
	printf ("The directories are -->\n");
	while(temp != NULL)
	{
		printf("%s\n", temp->dirname);
		temp = temp->link;
	}
	return;
}

void append_directory(struct directory **p)
{
	struct directory *temp;
	temp = (*p);
	char name[100];
	struct directory *new_dir;
	if (temp == NULL)
	{
		temp = (struct directory *)malloc(sizeof(struct directory));
		printf("Please enter the name of the new directory\n");
		scanf("%s", name);
		strcpy(temp->dirname, name);
		temp->link = NULL;
		temp->files = NULL;
		(*p) = temp;
		return;
	}
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	new_dir = (struct directory *)malloc(sizeof(struct directory));
	printf("Please enter the name of the new directory\n");
	scanf("%s", name);
	strcpy(new_dir->dirname, name);
	new_dir->link = NULL;
	new_dir->files = NULL;
	temp->link = new_dir;
	return;
}

void display_files(struct directory **p)
{
	struct file *temp;
	temp = (*p)->files;
	if (temp == NULL)
	{
		printf("No files present in the directory\n");
		return;
	}
	printf("The files in the directory are -->\n");
	while (temp != NULL)
	{
		printf("%s\n", temp->filename);
		temp = temp->link;
	}
	return;
}

struct directory *search_for_directory(struct directory **p, char a[])
{
	struct directory *temp;
	temp = (*p);
	if (temp == NULL)
	{
		printf("No directories added to the root directory\n");
		return NULL;
	}
	while(temp != NULL)
	{
		if (strcmp(temp->dirname, a) == 0)
		{
			printf("Directory found\n");
			return temp;
		}
		temp = temp->link;
	}
	printf("No directory named %s\n", a);
	return NULL;
}

void delete_file(struct directory **p, char a[])
{
	struct file *tempfile;
	tempfile = (*p)->files;
	struct file *delfile;
	delfile = tempfile;
	if (tempfile == NULL)
	{
		printf("Empty directory\n");
		return;
	}

	if (strcmp(tempfile->filename, a) == 0)
	{
		(*p)->files = tempfile->link;
		free(tempfile);
		printf("Deleted file\n");
		return;
	}

	tempfile = tempfile->link;

	while (tempfile != NULL)
	{
		if (strcmp(tempfile->filename, a) == 0)
		{
			delfile->link = tempfile->link;
			free(tempfile);
			printf("Deleted File\n");
			return;
		}
		delfile = tempfile;
		tempfile = tempfile->link;
	}

	printf("No file named %s in the directory\n", a);
	return;
}

void search_file(struct directory **p, char a[])
{
	struct file *temp;
	temp = (*p)->files;
	if (temp == NULL)
	{
		printf("Empty directory\n");
		return;
	}
	while (temp != NULL)
	{
		if (strcmp(temp->filename, a) == 0)
		{
			printf("File found in the directory\n");
			return;
		}
		temp = temp->link;
	}
	printf("No file named %s found in the directory\n", a);
	return;
}

void delete_directory(struct directory **p, char a[])
{
	struct directory *temp;
	temp = (*p);
	struct directory *t;
	t = (*p);
	if (temp == NULL)
	{
		printf("No directories in ROOT\n");
		return;
	}
	if (strcmp(t->dirname, a) == 0)
	{
		(*p) = t->link;
		free(t);
		printf("Directory deleted\n");
		return;
	}
	temp = temp->link;
	while (temp != NULL)
	{
		if (strcmp(temp->dirname, a) == 0)
		{
			t->link = temp->link;
			free (temp);
			printf("Directory deleted\n");
			return;
		}
		t = temp;
		temp = temp->link;
	}
	printf("No directory named %s found in ROOT\n", a);
	return;
}

void create_file(struct directory **p, char a[])
{
	struct file *temp, *newfile;
	temp = (*p)->files;
	newfile = (struct file *)malloc(sizeof(struct file));
	strcpy(newfile->filename, a);
	newfile->link = NULL;
	if (temp == NULL)
	{
		(*p)->files = newfile;
		printf("File created\n");
		return;
	}
	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = newfile;
	printf("File created\n");
	return;
}
