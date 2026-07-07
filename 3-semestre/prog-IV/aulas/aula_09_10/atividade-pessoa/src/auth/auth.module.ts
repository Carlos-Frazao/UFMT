import { Module } from '@nestjs/common';
import { AuthService } from './auth.service';
import { AuthController } from './auth.controller';
import { UsuarioModule } from '../usuario/usuario.module';
import { JwtModule } from '@nestjs/jwt';

@Module({
  imports: [
    UsuarioModule, // Importa o módulo de usuário para podermos buscar no banco
    JwtModule.register({
      secret: 'minha_chave_secreta_super_segura', // Chave para assinar o token
      signOptions: { expiresIn: '1h' }, // O token vai durar 1 hora
    }),
  ],
  controllers: [AuthController],
  providers: [AuthService],
})
export class AuthModule {}