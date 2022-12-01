using bytebank.Funcionarios;
using bytebank.Parceria;
using bytebank.Titular;
using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.SistemaInterno
{
    public class SistemaInterno
    {
        public bool Logar(IAutenticavel funcionario, string senha, string login)
        {
            bool usuarioAutencicado = funcionario.Autenticar(senha, login);

//            Console.Write(funcionario.Nome);
            if (usuarioAutencicado)
                Console.WriteLine(" -> Boas vindas ao sistema");
            else
                Console.WriteLine(" -> Senha incorreta");

            return usuarioAutencicado;
        }


    }
}
