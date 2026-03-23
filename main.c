#include "push_swap.h"

void print_bench(double disorder, char *strat, char *complex)
{
    write(2, "\n[bench] Disorder: ", 19);
    ft_putnbr_fd((int)(disorder * 100), 2);
    write(2, "%\n", 2);
    write(2, "[bench] Strategy: ", 18);
    write(2, strat, ft_strlen(strat));
    write(2, "\n[bench] Complexity: ", 21);
    write(2, complex, ft_strlen(complex));
    write(2, "\n", 1);
}

void run_adaptive(t_node **a, t_node **b, double d)
{
	if (d < 0.2)
		simple_sort(a, b);
	else if (d < 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}
/*
void run_adaptive(t_node **a, t_node **b, double d, int bench)
{
    if (d < 0.2)
    {
        if (bench) print_bench(d, "Simple Sort", "O(n2)");
        simple_sort(a, b);
    }
    else if (d < 0.5)
    {
        if (bench) print_bench(d, "Chunk Sort", "O(n*sqrt(n))");
        chunk_sort(a, b);
    }
    else
    {
        if (bench) print_bench(d, "Radix Sort", "O(n log n)");
        radix_sort(a, b);
    }
}
*/


int main(int argc, char **argv)
{
    t_node *a;
    t_node *b = NULL;
    char *mode = "--adaptive";
    int bench = 0;
    int i = 1;

    if (argc < 2) return (0);

    // Парсинг флагов
    while (i < argc && argv[i][0] == '-')
    {
        if (ft_strcmp(argv[i], "--bench") == 0) bench = 1;
        else if (ft_strcmp(argv[i], "--simple") == 0) mode = "--simple";
        else if (ft_strcmp(argv[i], "--medium") == 0) mode = "--medium";
        else if (ft_strcmp(argv[i], "--complex") == 0) mode = "--complex";
        else if (ft_strcmp(argv[i], "--adaptive") == 0) mode = "--adaptive";
        i++;
    }

    if (i >= argc) return (0);

    a = parse_args(argc - i + 1, &argv[i - 1]);
    index_stack(a);
    double disorder = compute_disorder(a);

    int size = stack_size(a);

	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}

	// 1. Выполнение сортировки
	if (size == 2)
		sa(&a);
	else if (size == 3)
		sort_3(&a);
	else if (size == 5)
		sort_5(&a, &b);
	else if (ft_strcmp(mode, "--simple") == 0)
		simple_sort(&a, &b);
	else if (ft_strcmp(mode, "--medium") == 0)
		chunk_sort(&a, &b);
	else if (ft_strcmp(mode, "--complex") == 0)
		radix_sort(&a, &b);
	else
		run_adaptive(&a, &b, disorder);

	// 2. Печать статистики ОДИН РАЗ в конце
	if (bench)
	{
		char *s_name = "Adaptive Selection";
		char *c_class = "Mixed";

		if (size <= 5) { s_name = "Small Sort"; c_class = "O(1)"; }
		else if (ft_strcmp(mode, "--simple") == 0) { s_name = "Simple Sort"; c_class = "O(n2)"; }
		else if (ft_strcmp(mode, "--medium") == 0) { s_name = "Chunk Sort"; c_class = "O(n*sqrt(n))"; }
		else if (ft_strcmp(mode, "--complex") == 0) { s_name = "Radix Sort"; c_class = "O(n log n)"; }
		else if (disorder < 0.2) { s_name = "Simple (Adaptive)"; c_class = "O(n2)"; }
		else if (disorder < 0.5) { s_name = "Chunk (Adaptive)"; c_class = "O(n*sqrt(n))"; }
		else { s_name = "Radix (Adaptive)"; c_class = "O(n log n)"; }

		print_bench(disorder, s_name, c_class);
		count_op(NULL, 2); // Печать счетчика из stack_utils.c
	}

	free_stack(&a);
	free_stack(&b);
	return (0);
    /*
    // 1. Сначала проверяем, не отсортирован ли стек уже
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }

    // 2. Если стек маленький — используем оптимальные алгоритмы
    if (size == 2)
        sa(&a);
    else if (size == 3)
        sort_3(&a);
    else if (size == 5)
        sort_5(&a, &b);
    
    // 3. Если стек большой — используем выбор стратегии
    else if (ft_strcmp(mode, "--simple") == 0)
    {
        if (bench) print_bench(disorder, "Simple Sort", "O(n2)");
        simple_sort(&a, &b);
    }
    else if (ft_strcmp(mode, "--medium") == 0)
    {
        if (bench) print_bench(disorder, "Chunk Sort", "O(n*sqrt(n))");
        chunk_sort(&a, &b);
    }
    else if (ft_strcmp(mode, "--complex") == 0)
    {
        if (bench) print_bench(disorder, "Radix Sort", "O(n log n)");
        radix_sort(&a, &b);
    }
    else // --adaptive
        run_adaptive(&a, &b, disorder, bench);

    if (ft_strcmp(mode, "--simple") == 0)
        simple_sort(&a, &b);
    else if (ft_strcmp(mode, "--medium") == 0)
        chunk_sort(&a, &b);
    else if (ft_strcmp(mode, "--complex") == 0)
        radix_sort(&a, &b);
    else
        run_adaptive(&a, &b, disorder, bench);

    // 1. Проверяем, не отсортирован ли стек уже
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }

    // 2. ВЫБОР АЛГОРИТМА (Сначала определяем, ЧЕМ сортируем)
    // Мы не запускаем их сразу, а выбираем один путь
    if (size == 2)
        sa(&a);
    else if (size == 3)
        sort_3(&a);
    else if (size == 5)
        sort_5(&a, &b);
    else 
    {
        // Только если чисел > 5, смотрим на флаги и адаптивность
        if (ft_strcmp(mode, "--simple") == 0)
            simple_sort(&a, &b);
        else if (ft_strcmp(mode, "--medium") == 0)
            chunk_sort(&a, &b);
        else if (ft_strcmp(mode, "--complex") == 0)
            radix_sort(&a, &b);
        else // --adaptive
            run_adaptive(&a, &b, disorder, 0); // Передаем 0, чтобы не печатать внутри
    }

    // 3. ПЕЧАТЬ BENCHMARK (В самом конце, в stderr)
    if (bench)
    {
        char *strat_name = "Adaptive Selection";
        char *comp_class = "Mixed";
        
        if (ft_strcmp(mode, "--simple") == 0) { strat_name = "Simple Sort"; comp_class = "O(n2)"; }
        else if (ft_strcmp(mode, "--medium") == 0) { strat_name = "Chunk Sort"; comp_class = "O(n*sqrt(n))"; }
        else if (ft_strcmp(mode, "--complex") == 0) { strat_name = "Radix Sort"; comp_class = "O(n log n)"; }
        
        print_bench(disorder, strat_name, comp_class);
    }

    // ... в самом конце main.c перед free_stack ...
    if (bench)
    {
        char *strat_name = "Adaptive Selection";
        char *comp_class = "Mixed";
        
        // Определяем имя для bench
        if (size <= 5) { strat_name = "Small Sort"; comp_class = "O(1)/O(n2)"; }
        else if (ft_strcmp(mode, "--simple") == 0) { strat_name = "Simple Sort"; comp_class = "O(n2)"; }
        else if (ft_strcmp(mode, "--medium") == 0) { strat_name = "Chunk Sort"; comp_class = "O(n*sqrt(n))"; }
        else if (ft_strcmp(mode, "--complex") == 0) { strat_name = "Radix Sort"; comp_class = "O(n log n)"; }
        else if (disorder < 0.2) { strat_name = "Simple (Adaptive)"; comp_class = "O(n2)"; }
        else if (disorder < 0.5) { strat_name = "Chunk (Adaptive)"; comp_class = "O(n*sqrt(n))"; }
        else { strat_name = "Radix (Adaptive)"; comp_class = "O(n log n)"; }

        print_bench(disorder, strat_name, comp_class); // Твоя функция для Disorder
        count_op(NULL, 2); // НОВАЯ ФУНКЦИЯ: напечатает все кол-во операций
    }
    free_stack(&a);
    free_stack(&b);
    return (0);*/
}