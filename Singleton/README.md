# Singleton
O padrão de projeto Singleton garante que a classe possui somente uma instância e que possui um ponto de acesso global a essa instância.
Em CPP é necessário criar algumas estruturas para garantir que esta classe se mantenha singleton mesmo em ambientes multithread.
Para atingir esse comportamento utilizamos o `mutex`, excluimos o construtor de cópias e o operador de atribuição.
