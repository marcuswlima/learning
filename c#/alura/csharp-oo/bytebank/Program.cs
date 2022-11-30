using System;
using bytebank;


///*
//ContaCorrente contaDoAndre = new ContaCorrente();
//contaDoAndre.titular = "Andre Silva";
//contaDoAndre.numero_agencia = 15;
//contaDoAndre.conta = "1010-X";
//contaDoAndre.saldo = 100;
//Console.WriteLine("Saldo da conta do Andre = " + contaDoAndre.saldo);
//contaDoAndre.Depositar(3);
//Console.WriteLine("Saldo da conta do Andre = " + contaDoAndre.saldo);
//Produto produtoExemplo = new Produto();
//produtoExemplo.nome = "ExemploExemplo";
//Console.WriteLine("O nome do produte é : " + produtoExemplo.nome);
//*/

//ContaCorrente conta = new ContaCorrente();
//conta.ToShow("ContaZerada");

//conta.titular = "Andre Silva";
//conta.agencia = 15;
//conta.conta = "1010-X";
//conta.saldo = 1000;
//conta.ToShow("Apos Setagem inicial");


//conta.Depositar(2);
//conta.ToShow("Após deposito de 2");

//bool tentativaDeSaque=conta.Sacar(800);
//if (tentativaDeSaque)
//    Console.WriteLine("Sucesso");
//else
//    Console.WriteLine("Falhou");

//conta.ToShow("Após saque");

//Console.ReadKey();

/*
Cliente cliente = new Cliente();
cliente.nome = "Marcus";
cliente.cpf = "123456789";
cliente.profissao = "Analista";
ContaCorrente contaDoAndre = new ContaCorrente();
contaDoAndre.titular = cliente;
contaDoAndre.agencia = 15;
contaDoAndre.conta = "1010-X";
contaDoAndre.saldo = 100;
contaDoAndre.ToShow("Após saque");

Cliente titular = new();
titular.Nome = "Marcus";
titular.Cpf = "59045108291";
titular.Profissao = "Servidor Público";


ContaCorrente conta3 = new();
conta3.Saldo=100;
conta3.Titular = titular;
conta3.Agencia = 1234;
conta3.Conta = "5678";
conta3.ToShow("Inicio");

conta3.Depositar(300);
conta3.ToShow("Apos deposito");

conta3.Sacar(5);
conta3.ToShow("Apos Saque");

*/
/*
ContaCorrente conta4 = new(18,"1234", "Marcus William");
conta4.ToShow("Apos Construcao");
//conta4.Depositar(300);
//conta4.ToShow("Apos deposito");
//bool logico=conta4.Sacar(3000000.2);
//conta4.ToShow("Apos Saque");

ContaCorrente conta5 = new(18, "1235", "Santos Lima");
conta5.ToShow("Apos Construcao");
//conta5.Depositar(3);
//conta5.ToShow("Apos deposito");
conta5.Transferir(1000, conta4);
conta4.ToShow("Apos transf");
conta5.ToShow("Apos transf");
*/

ContaCorrente conta4 = new(18, "1234", "Marcus William");
Console.WriteLine(ContaCorrente.TotalContasCriadas);
ContaCorrente conta5 = new(18, "1234", "Marcus William");
Console.WriteLine(ContaCorrente.TotalContasCriadas);
ContaCorrente conta6 = new(18, "1234", "Marcus William");
Console.WriteLine(ContaCorrente.TotalContasCriadas);