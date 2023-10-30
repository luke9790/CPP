/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:53:37 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/30 10:48:56 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
Battezziamo gli elementi utili per semplificare la lettura del codice (e scrivere meno)
*/

const std::string inputvalidi("1234567890 ");
std::vector<int>	PmergeMe::vettore;
std::deque<int>		PmergeMe::dique;

/*
Serve per stampare gli elementi del container dopo l'evento (after o before), separati da uno spazio 
l'un l'altro.
*/

template<typename T>
void PmergeMe::PrintContainer(const T& container, const std::string& event)
{
	std::cout << event << "	";
	std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

/*
Controlliamo che non ci siano input sbagliati (quindi solo cifre o spazio), poi usiamo atoi 
per inserirle nel container di riferimento come integer.
*/
void PmergeMe::Parsing(char** av)
{
	for (int i = 1; av[i] != 0; ++i)
	{
		std::string str_arg(av[i]);
		for (size_t i = 0; i < str_arg.size( ); i++)
		{
			if (inputvalidi.find(str_arg.at(i)) == std::string::npos)
				throw std::invalid_argument("Error.");
		}
		PmergeMe::FillContainers(std::atoi(av[i]));
	}
}

/* Dobbiamo inserire gli elementi passati come input nei due container, quindi 
controlliamo che non siano int max e poi li pushiamo in ciascun container */

void PmergeMe::FillContainers(int value)
{
	if (value > __INT_MAX__)
			throw std::invalid_argument("Error: number exceeds int max.");
	vettore.push_back(value);
	dique.push_back(value);
}

/*
si basa su due iteratori begin e end. Dereferenziamo su value l'iteratore element a partire
dal primo indice. Per ogni iterazione compariamo value con gli elementi precedenti. 
Se ci sono elementi con valore piu grande li spostiamo in avanti finche' non abbiamo trovato 
la posizione ordinata di element. Ripetiamo per ogni elemento.
NB: Nel while shiftiamo j alla posizione successiva per non perdere il suo contenuto, nal caso limite
il nuovo elemento viene posizionato dopo begin, nell'altro element viene reinserito nella sua posizione originale.
*/

template<typename T>
void PmergeMe::InsertionSort(T begin, T end)
{
	int value;
	for (T element = begin + 1; element < end; ++element)
	{
		value = *element;
		T j = element - 1;
		while (j >= begin && *j > value)
		{
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = value;
	}
}

/*
con + di 7 elementi usiamo il merge, altrimenti l'insertion. Con mid troviamo 
la meta' del gruppo. Usiamo in modo ricursivo la funzione per continuare a dividere
a meta' le due meta' iniziali fino a che non sono gruppi minori di 8 elementi, che 
vengono riordinati con l'insertion sort. Finito il ciclo abbiamo due meta' in ordine,
usiamo merge e copy per riunirle e abbiamo fatto. (NB 7 e' un valore "random", threshold).
Merge riunisce due gruppi(begin-mid e mid-end, a partire da copy.begin), poi vengono rimessi
nel gruppo originale con copy.
*/

template<typename T, typename TT>
void	PmergeMe::MergeInsertionSort(T& container, TT begin, TT end)
{
	if (std::distance(begin, end) > 7)
	{
		TT mid = begin + std::distance(begin, end) / 2;
		PmergeMe::MergeInsertionSort(container, begin, mid);
		PmergeMe::MergeInsertionSort(container, mid, end);
		T copy(std::distance(begin, end));
		std::merge(begin, mid, mid, end, copy.begin());
		std::copy(copy.begin(), copy.end(), begin);
	}
	else
		PmergeMe::InsertionSort(begin, end);
}

/*
Clock_t e' il tipe per conservare il tempo del processore in clock ticks (integer) ma si basa
sui cicli del processore, quindi usiamo un double per convertirlo in secondi e avere piu precisione.
Sarebbe meglio ancora usare chrono ma non e' possibile con c++98.
*/

void PmergeMe::Exec(void)
{
    clock_t start, end;
	
   	PmergeMe::PrintContainer(vettore, "Before:");

    start = clock();
    PmergeMe::MergeInsertionSort(vettore, vettore.begin(), vettore.end());
    end = clock();

	PmergeMe::PrintContainer(vettore, "After:");

    double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << vettore.size() << " elements with std::vector : "
              << std::fixed << elapsed_time << "us" << std::endl;

    start = clock();
    PmergeMe::MergeInsertionSort(dique, dique.begin(), dique.end());
    end = clock();

    elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << dique.size() << " elements with std::deque : "
              << std::fixed << elapsed_time << "us" << std::endl;
}