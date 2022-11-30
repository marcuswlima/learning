using bytebank.Funcionarios;
using bytebank.Titular;
using System;
using System.Collections.Generic;
using System.Text;

namespace bytebank.utilitario
{
    public class GerenciadorDeBonificacao
    {
        private double totalBonificacao;
        public void Registrar(Funcionario funcionario)
        {
            this.totalBonificacao += funcionario.GetBonificacao();
        }

        public double GetBonificacao()
        {
            return this.totalBonificacao;
        }
    }
}
