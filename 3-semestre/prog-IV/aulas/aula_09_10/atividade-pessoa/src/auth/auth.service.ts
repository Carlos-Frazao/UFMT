import { Injectable, UnauthorizedException } from '@nestjs/common';
import { UsuarioService } from '../usuario/usuario.service';
import { JwtService } from '@nestjs/jwt';
import * as bcrypt from 'bcryptjs';

@Injectable()
export class AuthService {
  constructor(
    private usuarioService: UsuarioService,
    private jwtService: JwtService,
  ) {}

  async login(email: string, senhaDigitada: string) {
    // 1. Busca o usuário pelo e-mail
    const usuario = await this.usuarioService.findByEmail(email);

    // 2. Se não achar o usuário, bloqueia
    if (!usuario) {
      throw new UnauthorizedException('Credenciais inválidas');
    }

    // 3. Compara a senha digitada com a criptografada do banco
    const senhaValida = await bcrypt.compare(senhaDigitada, usuario.senha);
    if (!senhaValida) {
      throw new UnauthorizedException('Credenciais inválidas');
    }

    // 4. Se tudo estiver certo, gera o Payload (corpo do token) e assina 
    const payload = { sub: usuario.id, email: usuario.email };
    return {
      access_token: await this.jwtService.signAsync(payload),
    };
  }
}