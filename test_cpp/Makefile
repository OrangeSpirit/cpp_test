all:
	gcc -std=c++17 -Wall -Werror -Wextra -pedantic -g list.cpp -lstdc++ -lm
	./a.out

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt *.dSYM *.out

copy:
	gcc -std=c++17 -Wall -Werror -Wextra -pedantic -g copy.cpp -lstdc++
	./a.out

valgrind:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt *.dSYM *.out
	gcc -std=c++17 -Wall -Werror -Wextra -pedantic -g s21_matrix.cpp -lstdc++ -lm
	valgrind --tool=memcheck --leak-check=yes  ./a.out

valgrind_long:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt *.dSYM *.out
	gcc -std=c++17 -Wall -Werror -Wextra -pedantic -g s21_matrix.cpp -lstdc++ -lm
	valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./a.out