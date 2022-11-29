using System;
using System.Collections.Generic;
using System.Text;

public class Cliente
{

    public string Nome { get; set; }
    public string Cpf { get; set; }
    public string Profissao { get; set; }

    public Cliente(string nome)
    {
        this.Nome = nome;
    }
}
