
#include "../incl/rubik.h"

static void print_color(char c)
{
    if (c == 'R')
        printf(D_RED);
    else if (c == 'G')
        printf(D_GREEN);
    else if (c == 'B')
        printf(D_BLUE);
    else if (c == 'Y')
        printf(D_YELLOW);
    else if (c == 'O')
        printf(D_YELLOW);
    printf("%c", c);
    printf(D_WHITE);
}

static char *ft_print_color_face(int face_nb)
{
    if (face_nb == E_WHITE)
        return("white");
    else if (face_nb == E_BLUE)
        return ("blue");
    else if (face_nb == E_RED)
        return ("red");
    else if (face_nb == E_GREEN)
        return ("green");
    else if (face_nb == E_ORANGE)
        return ("orange");
    else if (face_nb == E_YELLOW)
        return ("yellow");
    else
        return ("error");
}

static void ft_db_print_faces(char ***face)
{
	printf("### Print faces ###\n\n");

    for (int face_nb = 0; face_nb < 6; face_nb++)
    {
        printf("Face Nb[%d] Color[%s]\n", 
                face_nb + 1,
                ft_print_color_face(face_nb));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                print_color(face[face_nb][i][j]);
            printf("\n");
        }
    }
}

void	ft_db_print_cube(t_cube *cube)
{
    ft_db_print_faces(cube->face);
}
