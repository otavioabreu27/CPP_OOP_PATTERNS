# Observer
O padrão Observer é muito interessante em alguns casos especificos. Sua relação de gestão de uma classe para outras N é o seu principal ponto positivo. Além de que é possivel criar classes abstratas pra ambas as funções (Observador e Sujeuito) o que garante desacoplamentos possíveis provenientes dessa relação.

## Sujeito
Classe capaz de gerenciar observadores (registrar, desregistrar e notificar).

É a ponta 1 da relaçao 1 -> N entre Sujeitos e Observadores.


## Observador
Entidade que deseja ser informada de mudanças no sujeito. Deve implementar a interface de atualização.

![ExemploObserver](https://github.com/otavioabreu27/CPP_OOP_PATTERNS/blob/main/media/ObserverExample.png)
