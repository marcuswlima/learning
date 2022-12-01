using bytebank.SistemaInterno;
using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.Parceria
{
    public class ParceiroComercial : IAutenticavel
    {
        public string Login { get; set; }
        public string Senha { get; set; }
        public string Nome { get; set; }

        public bool Autenticar(string senha, string login)
        {
            return this.Senha == senha;
        }

    }
}
