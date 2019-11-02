/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarini <yfarini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:19:54 by yfarini           #+#    #+#             */
/*   Updated: 2019/11/01 23:14:00 by ybarhdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <stdio.h>
# include <stddef.h>
# include <signal.h>
# include <stdbool.h>
#include <string.h>
/*
* THIS IS NOT MY CODE
*/
int orginal_crash;
int ft_crash;
pid_t pid;
bool has_segfault_ft;
bool has_segfault_org;
int a;
# define TEST_SEGFAULT(x,y) do { \
	if ((pid = fork()) < 0) \
		exit(EXIT_FAILURE); \
	if (pid == 0) { \
		do { x } while(0); \
		exit(EXIT_SUCCESS); \
	} else { \
		wait(&pid); \
		y = WIFSIGNALED(pid); \
	} \
} while(0);
/********************************/
#define TESTER(f) \
	TEST_SEGFAULT(f,has_segfault_org)\
	TEST_SEGFAULT(ft_##f,has_segfault_ft)\
		if(!has_segfault_org && has_segfault_ft){\
			write(1,"\033[31mKO \033[0m(",13);\
			write(1,#f,strlen(#f));\
			write(1,") ",2);}\
		else\
			write(1,"\033[32mOK\033[0m ",13);\


int main()
{
	
	printf("\nft_memcpy\n");
	TESTER(memcpy(NULL,NULL,0);)
	TESTER(memcpy("NULL",NULL,0);)
	TESTER(memcpy(NULL,"NULL",0);)
	TESTER(memcpy("NULL","NULL",0);)
	TESTER(memcpy(NULL,NULL,1);)
	TESTER(memcpy("NULL",NULL,1);)
	TESTER(memcpy(NULL,"NULL",1);)
	TESTER(memcpy("NULL","NULL",1);)
	TESTER(memcpy("NULLO",NULL,3);)
	TESTER(memcpy(NULL,"NULLO",3);)
	TESTER(memcpy("NULLO","NULL",3);)
	printf("\nft_memccpy\n");
	TESTER(memccpy(NULL,NULL,1,0);)
	TESTER(memccpy("NULL",NULL,1,0);)
	TESTER(memccpy(NULL,"NULL",1,0);)
	TESTER(memccpy("NULL","NULL",1,0);)
	TESTER(memccpy(NULL,NULL,1,1);)
	TESTER(memccpy("NULL",NULL,1,1);)
	TESTER(memccpy(NULL,"NULL",1,1);)
	TESTER(memccpy("NULL","NULL",1,1);)
	TESTER(memccpy(NULL,NULL,'L',3);)
	TESTER(memccpy("NULL",NULL,'L',3);)
	TESTER(memccpy(NULL,"NULL",'L',3);)
	TESTER(memccpy("NULL","NULL",'L',3);)
	TESTER(memccpy(NULL,NULL,'L',3);)
	TESTER(memccpy("NULLO",NULL,'L',3);)
	TESTER(memccpy(NULL,"NULLO",'L',3);)
	TESTER(memccpy("NULLO","NULL",'L',3);)
	printf("\nft_memmove\n");
	TESTER(memmove(NULL,NULL,0);)
	TESTER(memmove("NULL",NULL,0);)
	TESTER(memmove(NULL,"NULL",0);)
	TESTER(memmove("NULL","NULL",0);)
	TESTER(memmove(NULL,NULL,1);)
	TESTER(memmove("NULL",NULL,1);)
	TESTER(memmove(NULL,"NULL",1);)
	TESTER(memmove("NULL","NULL",1);)
	TESTER(memmove("NULLO",NULL,3);)
	TESTER(memmove(NULL,"NULLO",3);)
	TESTER(memmove("NULLO","NULL",3);)
	printf("\nft_memcmp\n");
	TESTER(memcmp(NULL,NULL,0);)
	TESTER(memcmp("NULL",NULL,0);)
	TESTER(memcmp(NULL,"NULL",0);)
	TESTER(memcmp("NULL","NULL",0);)
	TESTER(memcmp(NULL,NULL,1);)
	TESTER(memcmp("NULL",NULL,1);)
	TESTER(memcmp(NULL,"NULL",1);)
	TESTER(memcmp("NULL","NULL",1);)
	TESTER(memcmp("NULLO",NULL,3);)
	TESTER(memcmp(NULL,"NULLO",3);)
	TESTER(memcmp("NULLO","NULL",3);)
	printf("\nft_memchr\n");
	TESTER(memchr(NULL,0,0);)
	TESTER(memchr(NULL,0,1);)
	TESTER(memchr("NULL",0,0);)
	printf("\nft_memset\n");
	TESTER(memset(NULL,0,0);)
	TESTER(memset(NULL,0,1);)
	TESTER(memset("NULL",0,0);)
	printf("\nft_strlen\n");
	TESTER(strlen(NULL);)
	printf("\nft_strchr\n");
	TESTER(strchr(NULL,0);)
	TESTER(strchr("NULL",0);)
	printf("\nft_strlcat\n");
	TESTER(strlcat(NULL,NULL,0);)
	TESTER(strlcat("NULL",NULL,0);)
	TESTER(strlcat(NULL,"NULL",0);)
	TESTER(strlcat("NULL","NULL",0);)
	TESTER(strlcat(NULL,NULL,1);)
	TESTER(strlcat("NULL",NULL,1);)
	TESTER(strlcat(NULL,"NULL",1);)
	TESTER(strlcat("NULL","NULL",1);)
	TESTER(strlcat("NULLO",NULL,3);)
	TESTER(strlcat(NULL,"NULLO",3);)
	TESTER(strlcat("NULLO","NULL",3);)
	printf("\nft_strlcpy\n");
	TESTER(strlcpy(NULL,NULL,0);)
	TESTER(strlcpy("NULL",NULL,0);)
	TESTER(strlcpy(NULL,"NULL",0);)
	TESTER(strlcpy("NULL","NULL",0);)
	TESTER(strlcpy(NULL,NULL,1);)
	TESTER(strlcpy("NULL",NULL,1);)
	TESTER(strlcpy(NULL,"NULL",1);)
	TESTER(strlcpy("NULL","NULL",1);)
	TESTER(strlcpy("NULLO",NULL,3);)
	TESTER(strlcpy(NULL,"NULLO",3);)
	TESTER(strlcpy("NULLO","NULL",3);)
	printf("\nft_strncmp\n");
	TESTER(strncmp(NULL,NULL,0);)
	TESTER(strncmp("NULL",NULL,0);)
	TESTER(strncmp(NULL,"NULL",0);)
	TESTER(strncmp("NULL","NULL",0);)
	TESTER(strncmp(NULL,NULL,1);)
	TESTER(strncmp("NULL",NULL,1);)
	TESTER(strncmp(NULL,"NULL",1);)
	TESTER(strncmp("NULL","NULL",1);)
	TESTER(strncmp("NULLO",NULL,3);)
	TESTER(strncmp(NULL,"NULLO",3);)
	TESTER(strncmp("NULLO","NULL",3);)
	printf("\nft_strnstr\n");
	TESTER(strnstr(NULL,NULL,0);)
	TESTER(strnstr("NULL",NULL,0);)
	TESTER(strnstr(NULL,"NULL",0);)
	TESTER(strnstr("NULL","NULL",0);)
	TESTER(strnstr(NULL,NULL,1);)
	TESTER(strnstr("NULL",NULL,1);)
	TESTER(strnstr(NULL,"NULL",1);)
	TESTER(strnstr("NULL","NULL",1);)
	TESTER(strnstr("NULLO",NULL,3);)
	TESTER(strnstr(NULL,"NULLO",3);)
	TESTER(strnstr("NULLO","NULL",3);)
	TESTER(strnstr(NULL,"",3);)
}
