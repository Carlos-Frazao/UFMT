import { Module } from '@nestjs/common';
import { TypeOrmModule } from '@nestjs/typeorm';
import { AppController } from './app.controller';
import { AuthModule } from './auth/auth.module';
import { UsuarioModule } from './usuario/usuario.module';
import { PersonagemModule } from './personagem/personagem.module';

@Module({
  imports: [
    TypeOrmModule.forRoot({
      type: 'sqljs',
      location: 'trabalho-02.sqlite',
      autoSave: true,
      autoLoadEntities: true,
      synchronize: true,
    }),
    UsuarioModule,
    AuthModule,
    PersonagemModule,
  ],
  controllers: [AppController],
})
export class AppModule {}
