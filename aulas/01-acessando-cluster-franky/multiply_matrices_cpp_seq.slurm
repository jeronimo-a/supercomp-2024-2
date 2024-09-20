#!/bin/bash
#SBATCH --job-name=multiply_matrices_cpp_seq
# Define o nome do job como "matrix_mult_openmp". Esse nome aparece nas listas de jobs e é útil para identificar o job.

#SBATCH --output=multiply_matrices_cpp_seq.out
# Especifica o arquivo onde a saída padrão (stdout) do job será salva.

#SBATCH --ntasks=1
# Define o número de tarefas que o job executará. Neste caso, o job executa uma única tarefa.

#SBATCH --time=00:10:00
# Define o tempo máximo de execução para o job. Neste caso, o job tem um tempo limite de 10 minutos. Se o job exceder esse tempo, ele será automaticamente encerrado.

#SBATCH --partition=normal
# Especifica a partição (ou fila) onde o job será submetido. Aqui, o job será submetido a fila "normal".

./seq
# Executa o programa compilado "seq" dentro do nó de computação.